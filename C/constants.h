#ifndef CONSTANTS_H_
#define CONSTANTS_H_

// [Symbolic constants]
// addresses for Port B in Flash A
#define pFlashA_PortA_Dir (volatile unsigned char *)0x20270006
#define pFlashA_PortA_Data (volatile unsigned char *)0x20270004

// names for codec registers, used for iCodec1836TxRegs[]
#define DAC_CONTROL_1 0x0000
#define DAC_CONTROL_2 0x1000
#define DAC_VOLUME_0 0x2000
#define DAC_VOLUME_1 0x3000
#define DAC_VOLUME_2 0x4000
#define DAC_VOLUME_3 0x5000
#define DAC_VOLUME_4 0x6000
#define DAC_VOLUME_5 0x7000
#define ADC_0_PEAK_LEVEL 0x8000
#define ADC_1_PEAK_LEVEL 0x9000
#define ADC_2_PEAK_LEVEL 0xA000
#define ADC_3_PEAK_LEVEL 0xB000
#define ADC_CONTROL_1 0xC000
#define ADC_CONTROL_2 0xD000
#define ADC_CONTROL_3 0xE000

// names for slots in ad1836 audio frame
#define INTERNAL_ADC_L0 0
#define INTERNAL_ADC_R0 2
#define INTERNAL_DAC_L0 0
#define INTERNAL_DAC_R0 2
#define INTERNAL_ADC_L1 1
#define INTERNAL_ADC_R1 3
#define INTERNAL_DAC_L1 1
#define INTERNAL_DAC_R1 3

// size of array iCodec1836TxRegs and iCodec1836RxRegs
#define CODEC_1836_REGS_LENGTH 11

// SPI transfer mode
#define TIMOD_DMA_TX 0x0003

// SPORT0 word length
#define SLEN_24 0x0017
#define SLEN_16 0x000F

// DMA flow mode
#define FLOW_1 0x1000

#endif
