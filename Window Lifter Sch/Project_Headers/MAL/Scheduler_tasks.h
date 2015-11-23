/*
 * Scheduler_tasks.h
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
 * $Source: Scheduler_tasks.h $
 * $Revision: A $
 * $Author: Jorge Salas $
 * $Date: 20/11/2015 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/**Function prototypes definition of ticks
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
 * $Log: Scheduler_tasks.h  $
  ============================================================================*/
#ifndef SCHEDULER_TASKS_H_
#define SCHEDULER_TASKS_H_


/* Includes */
/*============================================================================*/
#include "HAL/type_definitions.h"
#include "HAL/MPC5606B.h"
#include "MAL/Scheduler_typedefs.h"
#include "MAL/button.h"
#include "Application/Window_Lifter.h"
/* Constants and types */
/*============================================================================*/


/* Exported Variables */
/*============================================================================*/
extern	const S_TASK cas_TaskList[NUMBER_OF_TASKS];

/* Exported functions prototypes */
/*============================================================================*/


/* Functions prototypes */
/*============================================================================*/
void Task1_1ticks(void);
void Task2_2ticks(void);
void Task3_100ticks(void);
void Task4_500ticks(void);


#endif /* SCHEDULER_TASKS_H_ */ /* Notice: the file ends with a blank new line to avoid compiler warnings */





