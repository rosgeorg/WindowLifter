/*
 * button.h
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
 * $Source: button.h $
 * $Revision: A $
 * $Author: Benjamin Aguilar $
 * $Date: 20/11/2015 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** Validation of the debounce of button press and changes the states, based
 * on the 10 ms restriction for valid press
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
 * $Log: button.h  $
  ============================================================================*/
#ifndef BUTTON_H_
#define BUTTON_H_

/* Includes */
/*============================================================================*/
#include "HAL/GPIO.h"
#include "HAL/type_definitions.h"
#include "HAL/MPC5606B.h"
#include "Application/Window_lifter.h"
#include "MAL/LED.h"

/* Constants and types */
/*============================================================================*/
#define _0_ms         0
#define _10_ms        10

enum ESTATUS
{
	LWEAKNESS ,
	AUTOMATIC_UP,
	AUTOMATIC_DOWN,
	MANUAL_UP,
	MANUAL_DOWN,
	BUTTON_AS_UP,
	BUTTON_AS_DOWN,
	ANTIPINCH,
	LOCK_WL
};

enum MOVIMIENTO
{
	IDLE,
	UP,
	DOWN,
	PINCH
	
};

/* Exported Variables */
/*============================================================================*/


/* Exported functions prototypes */
/*============================================================================*/
extern void button_validation (void);


#endif /* BUTTON_H_ */ /* Notice: the file ends with a blank new line to avoid compiler warnings */






