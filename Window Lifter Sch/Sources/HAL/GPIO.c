/*
 * GPIO.c
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
 * $Source: GPIO.c $
 * $Revision: A $
 * $Author: Benjamin Aguilar $
 * $Date: 19/11/2015 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** Configuration of input push buttons and macros
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
/*                     |Window Lifter with scheduler|     1.0                 */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: GPIO.h  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "HAL/GPIO.h"


/* Constants and types  */
/*============================================================================*/



/* Variables */
/*============================================================================*/



/* Private functions prototypes */
/*============================================================================*/



/* Inline functions */
/*============================================================================*/




/* Private functions */
/*============================================================================*/
void GPIO_config(void)
{
	uint16_t lub_i;
  
    /* Set Port A as OUTPUT*/
  	for(lub_i=0;lub_i<12;lub_i++)
  	{
  		SIU.PCR[lub_i].R = 0x200;	
  	}
  	  	
  	/* Embedded board buttons */
  	SIU.PCR[BUTTON1].R = 0x100;	
  	SIU.PCR[BUTTON2].R = 0x100;
  	SIU.PCR[BUTTON3].R = 0x100;
  		
}



/* Exported functions */
/*============================================================================*/



 /* Notice: the file ends with a blank new line to avoid compiler warnings */

