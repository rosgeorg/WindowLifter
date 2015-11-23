/*
 * PIT.c
 *
 *  Created on: Nov 19, 2015
 *      Author: PUG
 */
/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: PIT.h $
 * $Revision: A $
 * $Author: Benjamin Aguilar $
 * $Date: 19/11/2015 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/**Initialization and configuration of periodic interrupt timer, set flag for 1 ms
*/
/*============================================================================*/
/* COPYRIGHT (C) CONTINENTAL AUTOMOTIVE 2014                                  */
/* AUTOMOTIVE GROUP, Interior Division, Body and Security                     */
/* ALL RIGHTS RESERVED                                                        */
/*                                                                            */
/* The reproduction, transmission, or use of this document or its content is  */
/* not permitted without express written authority. Offenders will be liable  */
/* for damages.                                                               */
/* All rights, including rights created by patent grant or registration of a  */
/* utility model or design, are reserved.                                     */
/*                                                                            */
/*============================================================================*/
/*============================================================================*/
/*                    REUSE HISTORY - taken over from                         */
/*============================================================================*/
/*  DATABASE           |        PROJECT     | FILE VERSION (AND INSTANCE)     */
/*----------------------------------------------------------------------------*/
/*                     | Window Lifter with Scheduler|       1.0              */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: PIT.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "HAL/PIT.h"

/* Constants and types  */
/*============================================================================*/



/* Variables */
/*============================================================================*/
T_UBYTE rbi_TickFlag = FALSE;


/* Private functions prototypes */
/*============================================================================*/



/* Inline functions */
/*============================================================================*/




/* Private functions */
/*============================================================================*/
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
	  rbi_TickFlag = TRUE;
    /* Clear  interrupt flag */
    PIT.CH[0].TFLG.B.TIF = 1;
  }
}

/* Exported functions */
/*============================================================================*/



 /* Notice: the file ends with a blank new line to avoid compiler warnings */

