#include "constants.h"
#include "isr.h"
#include "parameters.h"
#include "process_data.h"

// This function initializes and enables asynchronous memory banks in External
// Bus Interface Unit so that Flash A can be accessed.
void Init_EBIU(void) {
  *pEBIU_AMBCTL0 = 0x7bb07bb0;
  *pEBIU_AMBCTL1 = 0x7bb07bb0;
  *pEBIU_AMGCTL = 0x000f;
}

// This function initializes pin direction of Port A in Flash A to output.  The
// AD1836_RESET on the ADSP-BF533 EZ-KIT board is connected to Port A.
void Init_Flash(void) { *pFlashA_PortA_Dir = 0x1; }

volatile short sCodec1836TxRegs[CODEC_1836_REGS_LENGTH] = {
    DAC_CONTROL_1 | 0x010, DAC_CONTROL_2 | 0x000, DAC_VOLUME_0 | 0x3ff,
    DAC_VOLUME_1 | 0x3ff,  DAC_VOLUME_2 | 0x3ff,  DAC_VOLUME_3 | 0x3ff,
    DAC_VOLUME_4 | 0x3ff,  DAC_VOLUME_5 | 0x3ff,  ADC_CONTROL_1 | 0x000,
    ADC_CONTROL_2 | 0x020, ADC_CONTROL_3 | 0x000};

// This function sets up the SPI port to configure the AD1836. The content of
// the array sCodec1836TxRegs is sent to the codec.
void Init1836(void) {
  int i;
  int j;
  static unsigned char ucActive_LED = 0x01;

  // write to Port A to reset AD1836
  *pFlashA_PortA_Data = 0x00;

  // write to Port A to enable AD1836
  *pFlashA_PortA_Data = ucActive_LED;

  // wait to recover from reset
  for (i = 0; i < 0xf000; i++)
    ;

  // Enable PF4
  *pSPI_FLG = FLS4;
  // Set baud rate SCK = HCLK/(2*SPIBAUD) SCK = 2MHz
  *pSPI_BAUD = 16;
  // configure spi port
  // SPI DMA write, 16-bit data, MSB first, SPI Master
  *pSPI_CTL = TIMOD_DMA_TX | SIZE | MSTR;

  // Set up DMA5 to transmit
  // Map DMA5 to SPI
  *pDMA5_PERIPHERAL_MAP = 0x5000;

  // Configure DMA5
  // 16-bit transfers
  *pDMA5_CONFIG = WDSIZE_16;
  // Start address of data buffer
  *pDMA5_START_ADDR = (void *)sCodec1836TxRegs;
  // DMA inner loop count
  *pDMA5_X_COUNT = CODEC_1836_REGS_LENGTH;
  // Inner loop address increment
  *pDMA5_X_MODIFY = 2;

  // enable DMAs
  *pDMA5_CONFIG = (*pDMA5_CONFIG | DMAEN);
  // enable spi
  *pSPI_CTL = (*pSPI_CTL | SPE);

  // wait until dma transfers for spi are finished
  for (j = 0; j < 0xaff; j++)
    ;

  // disable spi
  *pSPI_CTL = 0x0000;
}

// Configure Sport0 for TDM mode, to transmit/receive data to/from the AD1836.
// Configure Sport for external clocks and frame syncs.
void Init_Sport0(void) {
  // Sport0 receive configuration
  // External CLK, External Frame sync, MSB first, Active Low
  // 24-bit data, Secondary side disable, Stereo frame sync enable
  *pSPORT0_RCR1 = RFSR | RCKFE;
  *pSPORT0_RCR2 = SLEN_16 | RSFSE;

  // Sport0 transmit configuration
  // External CLK, External Frame sync, MSB first, Active Low
  // 24-bit data, Secondary side disable, Stereo frame sync enable
  *pSPORT0_TCR1 = TFSR | TCKFE;
  *pSPORT0_TCR2 = SLEN_16 | TSFSE;
}

// Initialize DMA1 in autobuffer mode to receive and DMA2 in autobuffer mode to
// transmit.
void Init_DMA(void) {
  // Set up DMA1 to receive
  // Map DMA1 to Sport0 RX
  *pDMA1_PERIPHERAL_MAP = 0x1000;

  // Configure DMA1
  // Ping-Pong Buffer, the first half of RxBuffer is ping, the second half is
  // pong 16-bit transfer, Interrupt on inner loop completion, 2 dimensional,
  // Autobuffer mode
  *pDMA1_CONFIG = WNR | WDSIZE_16 | DI_EN | DI_SEL | DMA2D | FLOW_1;
  // Start address of data buffer
  *pDMA1_START_ADDR = (void *)RxBuffer;
  // DMA inner loop count
  *pDMA1_X_COUNT = 2 * H_I;
  // Inner loop address increment
  *pDMA1_X_MODIFY = 2;
  // DMA outer loop count
  *pDMA1_Y_COUNT = 2;
  // Outer address increment
  *pDMA1_Y_MODIFY = 2;

  // Set up DMA2 to transmit
  // Map DMA2 to Sport0 TX
  *pDMA2_PERIPHERAL_MAP = 0x2000;

  // Configure DMA2
  // Ping-Pong Buffer, the first half of TxBuffer is ping, the second half is
  // pong 16-bit transfers, 2 dimensional, Autobuffer mode
  *pDMA2_CONFIG = WDSIZE_16 | DMA2D | FLOW_1;
  // Start address of data buffer
  *pDMA2_START_ADDR = (void *)TxBuffer;
  // DMA inner loop count
  *pDMA2_X_COUNT = 2 * H_I;
  // Inner loop address increment
  *pDMA2_X_MODIFY = 2;
  // DMA outer loop count
  *pDMA2_Y_COUNT = 2;
  // Outer address increment
  *pDMA2_Y_MODIFY = 2;
}

// Initialize Interrupt for Sport0 RX
void Init_Sport_Interrupts(void) {
  // Set Sport0 RX (DMA1) interrupt priority to 2 = IVG9
  *pSIC_IAR0 = 0xffffffff;
  *pSIC_IAR1 = 0xffffff2f;
  *pSIC_IAR2 = 0xffffffff;

  // assign ISRs to interrupt vectors
  // Sport0 RX ISR -> IVG 9
  register_handler(ik_ivg9, Sport0_RX_ISR);

  // enable Sport0 RX interrupt
  *pSIC_IMASK = 0x00000200;
  ssync();
}

// Enable DMA1, DMA2, Sport0 TX and Sport0 RX
void Enable_DMA_Sport0(void) {
  // enable DMAs
  *pDMA2_CONFIG = (*pDMA2_CONFIG | DMAEN);
  *pDMA1_CONFIG = (*pDMA1_CONFIG | DMAEN);

  // enable Sport0 TX and RX
  *pSPORT0_TCR1 = (*pSPORT0_TCR1 | TSPEN);
  *pSPORT0_RCR1 = (*pSPORT0_RCR1 | RSPEN);
}
