/*
 * PIT.h
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
/** Initialization and configuration of periodic interrupt timer, set flag for 1 ms
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
 * $Log: PIT.h  $
  ============================================================================*/
#ifndef PIT_H_
#define PIT_H_

/* Includes */
/*============================================================================*/
#include "HAL/type_definitions.h"
#include "HAL/MPC5606B.h"
#include "Application/Window_Lifter.h"
#include "MAL/button.h"
#include "HAL/GPIO.h"
#include "MAL/LED.h"
#include "HAL/IntcInterrupts.h"
/* Constants and types */
/*============================================================================*/
#define    PITCHANNEL_0					0
#define    DEVICE_FREQUENCY           (T_ULONG)64000000
#define    CHANNEL_DESIRED_FREQUENCY   (T_ULONG)1000
#define    PIT_FREQUENCY_VALUE            	( ( DEVICE_FREQUENCY / CHANNEL_DESIRED_FREQUENCY ) - 1 )

/* Exported Variables */
/*============================================================================*/


/* Exported functions prototypes */
/*============================================================================*/
void PIT_device_init(void);

/* PIT channel configuration */
void PIT_channel_config(uint8_t channel);

/** PIT Start procedure */
void PIT_channel_active(uint8_t channel);

/** PIT Low level Stop procedure */
void PIT_channel_stop(uint8_t channel);

/** PIT Channel 0 ISR  */
void PIT_channel0_ISR(void);


#endif /* PIT_H_ */  /* Notice: the file ends with a blank new line to avoid compiler warnings */






