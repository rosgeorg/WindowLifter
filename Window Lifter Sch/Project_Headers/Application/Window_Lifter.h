/*
 * Window_Lifter.h
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
 * $Source: Window_Lifter.h $
 * $Revision: A $
 * $Author: Benjamin Aguilar $
 * $Date: 20/11/2015$
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** Definition of functions and periodic times for state machine
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
 * $Log: Window_Lifter.h  $
  ============================================================================*/
#ifndef WINDOW_LIFTER_H_
#define WINDOW_LIFTER_H_

/* Includes */
/*============================================================================*/
#include "HAL/GPIO.h"
#include "HAL/type_definitions.h"
#include "HAL/MPC5606B.h"
#include "MAL/Button.h"
#include "MAL/LED.h"

/* Constants and types */
/*============================================================================*/
#define _0_ms                       0
#define _10_ms                      10
#define _500_ms                     500
#define _400_ms                     300
#define _5_s                        5000
#define CLOSED                      10 	
#define OPEN                        65535

/* Exported Variables */
/*============================================================================*/


/* Exported functions prototypes */
/*============================================================================*/
void automatic_up(void);
void automatic_down(void);
void manual_up(void);
void manual_down(void);
void button_as_up(void);
void button_as_down(void);
void aintipinch(void);
void lock_wl(void);
void lweakness(void);
extern void State_Machine(void);


#endif /* WINDOW_LIFTER_H_ */  /* Notice: the file ends with a blank new line to avoid compiler warnings */






