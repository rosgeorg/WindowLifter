/*
 * GPIO.h
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
 * $Source: GPIO.h $
 * $Revision: A $
 * $Author: Benjamin Aguiar $
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
#ifndef GPIO_H_
#define GPIO_H_

/* Includes */
/*============================================================================*/
#include "HAL/type_definitions.h"
#include "HAL/MPC5606B.h"

/* Constants and types */
/*============================================================================*/
#define on 1
#define off 0
#define BUTTON1 64 /*S2*/
#define BUTTON2 65
#define BUTTON3 66
/* Input Buttons */
#define BUTTON_UP        SIU.GPDI[BUTTON1].B.PDI
#define BUTTON_DOWN      SIU.GPDI[BUTTON2].B.PDI
#define ANTI_PINCH       SIU.GPDI[BUTTON3].B.PDI
#define B_ACTIVE                  1
#define B_INACTIVE                0

/* Exported Variables */
/*============================================================================*/


/* Exported functions prototypes */
/*============================================================================*/
void GPIO_config(void);


#endif /* GPIO_H_ */  /* Notice: the file ends with a blank new line to avoid compiler warnings */





