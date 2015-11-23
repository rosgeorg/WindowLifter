/*
 * Scheduler.c
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
 * $Source: Scheduler.c $
 * $Revision: A $
 * $Author: Jorge Salas $
 * $Date: 20/11/2015 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** This file contains functions that help the system move through the different tasks
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
 * $Log: Scheduler.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "MAL/Scheduler.h"


/* Constants and types  */
/*============================================================================*/
T_ULONG rul_TimeCounter[NUMBER_OF_TASKS];


/* Variables */
/*============================================================================*/
T_ULONG lul_Position;
T_ULONG lul_ArrayPosition;

/* Private functions prototypes */
/*============================================================================*/



/* Inline functions */
/*============================================================================*/




/* Private functions */
/*============================================================================*/

/** 
 * This function set the value of Offset as the value of TimeCounter
*/
void init_Counters(void)
{
	for(lul_Position = 0; lul_Position < NUMBER_OF_TASKS; lul_Position++)
	{
		rul_TimeCounter[lul_Position] = cas_TaskList[NUMBER_OF_TASKS].Offset;
	}
}

/**
 * Check when a task is ready to start decrementing it's period to 0
 * and moving to the selected function with a pointer to function
*/
void Sch_Ex(void)
{
	
	while(1)
		{
			if(rbi_TickFlag == TRUE)
			{
				rbi_TickFlag = FALSE;
				for(lul_ArrayPosition = 0; lul_ArrayPosition < NUMBER_OF_TASKS; lul_ArrayPosition++)
				{
					if(rul_TimeCounter[lul_ArrayPosition] != 0)
					{
						rul_TimeCounter[lul_ArrayPosition]--;
					}
					else
					{
						rul_TimeCounter[lul_ArrayPosition] = cas_TaskList[lul_ArrayPosition].Period;
						cas_TaskList[lul_ArrayPosition].PtrToFunc();
					}
				}
			}
		}
}

/* Exported functions */
/*============================================================================*/



 /* Notice: the file ends with a blank new line to avoid compiler warnings */

