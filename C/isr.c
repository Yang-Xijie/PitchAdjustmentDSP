#include "isr.h"

#include "constants.h"
#include "process_data.h"

// This ISR is executed after a complete frame of input data has been received.
// The new samples are stored in iChannel0LeftIn, iChannel0RightIn,
// iChannel1LeftIn and iChannel1RightIn respectively.  Then the function
// ProcessData() is called in which user code can be executed. After that the
// processed values are copied from the variables iChannel0LeftOut,
// iChannel0RightOut, iChannel1LeftOut and iChannel1RightOut into the dma
// transmit buffer.
EX_INTERRUPT_HANDLER(Sport0_RX_ISR) {
  // confirm interrupt handling
  *pDMA1_IRQ_STATUS = 0x0001;
  // call function that contains user code
  ProcessData();
}
