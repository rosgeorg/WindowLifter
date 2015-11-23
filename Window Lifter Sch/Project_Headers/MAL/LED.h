/*
 * LED.h
 *
 *  Created on: Nov 20, 2015
 *      Author: PUG
 */
/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: LED.h $
 * $Revision: A $
 * $Author: Benjamin Aguilar $
 * $Date: 20/11/2015 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** Turn on the LED bar to indicate the initializacion of the window as closed 
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
 * $Log: LED.h  $
  ============================================================================*/
#ifndef LED_H_
#define LED_H_
/* Includes */
/*============================================================================*/
#include "HAL/type_definitions.h"
#include "HAL/MPC5606B.h"
#include "HAL/GPIO.h"



/* Constants and types  */
/*============================================================================*/
/****GPIO's****/

#define LED1      0
#define LED2      1
#define LED3      2
#define LED4      3
#define LED5      4
#define LED6      5
#define LED7      6
#define LED8      7
#define LED9      8
#define LED10      9 
#define LED_UP    10
#define LED_DOWN  11

/** Set LED */ 
#define LED_ON(channel)                     (SIU.GPDO[channel].B.PDO =  on)
/** Clear LED */ 
#define LED_OFF(channel)                    (SIU.GPDO[channel].B.PDO =  off)


/* Exported Variables */
/*============================================================================*/


/* Exported functions prototypes */
/*============================================================================*/
void window_closed (void);


 #endif /* LED_H_ */  /* Notice: the file ends with a blank new line to avoid compiler warnings */










