/*
 * Window_Lifter.c
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
 * $Source: Window_Lifter.c $
 * $Revision: A $
 * $Author: Benjamin Aguilar $
 * $Date: 20/11/2015$
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/**File with state machine and functions declaration with the coverage of all 
 * conditions regarding customer requirements
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
 * $Log: Window_Lifter.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "Application/Window_lifter.h"


/* Constants and types  */
/*============================================================================*/


/* Variables */
/*============================================================================*/
T_UWORD rub_LED_Position=LED10;
T_UWORD ruw_time_button=_0_ms, ruw_time_transition=_0_ms;
T_UWORD rub_State=LWEAKNESS;
volatile T_UWORD rub_Movement;

/* Private functions prototypes */
/*============================================================================*/



/* Inline functions */
/*============================================================================*/




/* Private functions */
/*============================================================================*/
void State_Machine(void)
{
	
	
	switch(rub_State)
	{
		case LWEAKNESS:
			lweakness ();
			//button_validation();     
			break;
			
		
		case AUTOMATIC_UP:
			automatic_up();
			break;
			
			
		case AUTOMATIC_DOWN:
			automatic_down();
			break;
		
			
		case MANUAL_UP:
			manual_up();
			break;
		
			
		case MANUAL_DOWN:
			manual_down();
			break;
			
						
		case BUTTON_AS_UP:
			button_as_up();
			break;
			
			
		case BUTTON_AS_DOWN:
			button_as_down();
			break;
			
			
		case ANTIPINCH:	
			aintipinch();
			break;
			
		case LOCK_WL:
			lock_wl();
			break;
	}  
	
}       








/**************************************************************/
void automatic_up(void)
{
	if((BUTTON_DOWN) || (ANTI_PINCH))
		{
			
			rub_State=LWEAKNESS;
		}
		else
		{
					
			
		ruw_time_transition++;
		
			if((rub_LED_Position>=LED1) && (ruw_time_transition==_400_ms))
			{
				LED_ON(rub_LED_Position); //Apagar el led correspondiente a Led_Position
				
				if(rub_LED_Position == 9)
				{
					rub_LED_Position = 9;
					ruw_time_transition=_0_ms;
					rub_State = LWEAKNESS;
				}
				else
				{
					rub_LED_Position++;
					ruw_time_transition=_0_ms;
				}
			}
			
		}
}

/*************** End function automatic_up ***************/


/**************************************************************/
void automatic_down(void)
{
	if(BUTTON_UP) 
	{
		
		rub_State=LWEAKNESS;
	}
	else
	{
				
	ruw_time_transition++;
	
		if((rub_LED_Position<=LED10) && (ruw_time_transition==_400_ms))
		{
			LED_OFF(rub_LED_Position); //Apagar el led correspondiente a Led_Position
			
			if(rub_LED_Position == 0)
			{
				rub_LED_Position = 0;
				ruw_time_transition=_0_ms;
				rub_State = LWEAKNESS;
			}
			else
			{
				rub_LED_Position--;
				ruw_time_transition=_0_ms;
			}
		}
		
	}
	
	
}
	

/*************** End function automatic_down ***************/

/**************************************************************/

void manual_up(void)
{
	
	if((BUTTON_DOWN == B_ACTIVE) || (ANTI_PINCH == B_ACTIVE))
		{
			LED_OFF(LED_UP);
			rub_State=LWEAKNESS;
			ruw_time_button=_0_ms;
		} 
	
	else
	{
		
		
		if(BUTTON_UP == B_ACTIVE)
		{
			
			ruw_time_transition++;
			if((ruw_time_transition == _400_ms) && (rub_LED_Position>=LED1))
			{
							
				LED_ON(rub_LED_Position); //Turns off LED based on variable "Led_Position"
				rub_LED_Position++;
				ruw_time_transition=_0_ms;
				
				if(rub_LED_Position == CLOSED)
				{
					rub_LED_Position = 9;
					ruw_time_transition=_0_ms;
					rub_State = LWEAKNESS;
				}
			 }
			else 
			{
				//nothing
			}
		}
		
		
	}
}



/*************** End function manual_up ***************/

/**************************************************************/

void manual_down(void)
{
	SIU.PCR[69].R = 0x200;
	SIU.GPDO[69].B.PDO=0;	
	if(BUTTON_UP == B_ACTIVE) 
		{
			LED_OFF(LED_DOWN);
			rub_State=LWEAKNESS;
			ruw_time_button=_0_ms;
		}    

	else
	{
				
		if(BUTTON_DOWN == B_ACTIVE) 
		{
			
			ruw_time_transition++;
			if((ruw_time_transition == _400_ms) && (rub_LED_Position<=LED10))
			{
							
				LED_OFF(rub_LED_Position); //Turns off LED based on variable "Led_Position"
				rub_LED_Position--;
				ruw_time_transition=_0_ms;
				
				if(rub_LED_Position == OPEN)
				{
				
					rub_LED_Position = 0;
					ruw_time_transition=_0_ms;
					rub_State = LWEAKNESS;
					
				}
			 }
			else 
			{
				
						
				//nothing
			}
		}
		
		
	}
}


/*************** End function manual_down *********************/



/**************************************************************/

void button_as_up(void)
{
	LED_ON(LED_UP);
	LED_OFF(LED_DOWN);
	ruw_time_transition=_0_ms;
	
	if((BUTTON_UP) && (rub_Movement==UP))
	{
		ruw_time_button++;
		if((ruw_time_button>_500_ms) && (BUTTON_UP==B_ACTIVE))
		{
			
			ruw_time_button=0;		
			rub_State=MANUAL_UP;
		}
		else
		{
			//nothing
		}
	}
	else
	{
		
		ruw_time_button=0;	
		rub_State=AUTOMATIC_UP;
	}
	
}  

/*************** End function button_as_up ***************/



/**************************************************************/

void button_as_down(void)
{
	LED_ON(LED_DOWN);
	LED_OFF(LED_UP);
	ruw_time_transition=_0_ms;
	
	if((BUTTON_DOWN) && (rub_Movement==DOWN))						
	{	
		
		ruw_time_button++;
		if((ruw_time_button >=_500_ms) && (BUTTON_DOWN==B_ACTIVE))
		{
			SIU.PCR[68].R = 0x200;
			SIU.GPDO[68].B.PDO=0;
			ruw_time_button=_0_ms;
			rub_State=MANUAL_DOWN;
		}
		else
		{
			//nothing
		}
		
		
	}
	else
		{
		
		ruw_time_button=0;
			rub_State=AUTOMATIC_DOWN;
			
		}
		
}
/*************** End function button_as_down ***************/

/**************************************************************/

void aintipinch(void)
{
	
	if(rub_Movement==PINCH)
	{
		LED_OFF(LED_UP);
		LED_ON(LED_DOWN);
		
				ruw_time_transition++;
					if((rub_LED_Position<=LED10) && (ruw_time_transition==_400_ms))
						{
					
							LED_OFF(rub_LED_Position); //Apagar el led correspondiente a Led_Position
							
							if(rub_LED_Position == 0)
							{
								
								rub_LED_Position = 0;
								ruw_time_transition=_0_ms;
								rub_State = LOCK_WL;
							}
							else
							{
								rub_LED_Position--;
								ruw_time_transition=_0_ms;
							}
						}
	}
	
}
/*************** End function antipinch ***************/


/**************************************************************/

void lock_wl(void)
{
	static T_UWORD luw_time_LOCK;
	 	luw_time_LOCK++;
	if(luw_time_LOCK==_5_s)
	{
		luw_time_LOCK=_0_ms;
		rub_State=LWEAKNESS;
	}
}   


/**************** End function lock_wl ***************/

/**************************************************************/

void lweakness(void)
{
	if (rub_Movement==DOWN)
	{
		rub_Movement=DOWN;
		rub_State=BUTTON_AS_DOWN;
	}
	else if (rub_Movement==UP)
	{
		rub_Movement=UP;
		rub_State=BUTTON_AS_UP;
	}
	else if (rub_Movement==PINCH)
	{
		rub_Movement=PINCH;
		rub_State=ANTIPINCH;
	}
	else
	{
		//nothing
	}
}

/*************** End function lweakness ***************/


/* Exported functions */
/*============================================================================*/



 /* Notice: the file ends with a blank new line to avoid compiler warnings */

