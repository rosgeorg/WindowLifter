/*
 * PIT.c
 *
 *  Created on: Nov 1, 2015
 *      Author: PUG
 */

#include "typedefs.h"
#include "IntcInterrupts.h"
#include "PIT.h"
#include "MPC5606B.h"
#include "Window_lifter.h"
#include "button.h"




void PIT_device_init(void) 
{
    PIT.PITMCR.R = 0x00000001;       /* Enable PIT and configure timers to stop in debug mode */
}

void PIT_channel_config(uint8_t channel) 
{
    PIT.CH[channel].LDVAL.R = PIT_FREQUENCY_VALUE;      /* PIT1 timeout --> Refer to PIT.h file for calculations */
        
   
  }


void PIT_channel_active(uint8_t channel)
{
    PIT.CH[channel].TCTRL.R = 0x000000003;            /* Enable PIT1 interrupt and make PIT active to count */
}

void PIT_channel_stop(uint8_t channel)
{
	PIT.CH[channel].TCTRL.R = 0x000000000;            /* Disable PIT channel interrupt and make PIT inactive to count */
}

void PIT_channel0_ISR(void)
{
  if (PIT.CH[0].TFLG.B.TIF)
  {
    /* Clear  interrupt flag */
    PIT.CH[0].TFLG.B.TIF = 1;
    State_Machine();

  
  }
}


