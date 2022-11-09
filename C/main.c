// Original Name: Talkthrough with FIR for the ADSP-BF533 EZ-KIT Lite
//
// Original Project Name: BF533 C Talkthrough TDM
//
// (C) Copyright 2003 - Analog Devices, Inc.  All rights reserved.
//
// Hardware: ADSP-BF533 EZ-KIT Board
//
// Connections:	Connect an input source (such as a radio) to the Audio input
// jack and an output source (such as headphones) to the Audio output jack
//
// Purpose: This program sets up the SPI port on the ADSP-BF533 to configure the
// AD1836 codec. The SPI port is disabled after initialization.  The data
// to/from the codec are transfered over SPORT0 in TDM mode.

#include <fract.h>

#include "all.h"
#include "ccblkfn.h"
#include "sysreg.h"

// After calling a few initalization routines, main() just waits in a loop
// forever.  The code to process the incoming data can be placed in the function
// `ProcessData()` in the file `process_data.c`.
void main(void) {
  sysreg_write(reg_SYSCFG, 0x32);  // Initialize System Configuration Register
  Init_EBIU();
  Init_Flash();
  Init1836();
  Init_Sport0();
  Init_DMA();
  Init_Sport_Interrupts();
  Enable_DMA_Sport0();

  while (1)
    ;
}
