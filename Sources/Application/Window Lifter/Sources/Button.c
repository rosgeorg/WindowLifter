/*
 * Button.c
 *
 *  Created on: Nov 2, 2015
 *      Author: PUG
 */
#include "button.h"

extern uint16_t rub_State;

void button_signal (void)
{
	static uint16_t lub_counter_button=0;
		
	
		if((BUTTON_DOWN == B_ACTIVE) && (BUTTON_UP == B_INACTIVE))
		{	
			
			lub_counter_button++;                       /*Increases counter to 10 milliseconds*/
			if(lub_counter_button>=_10_ms)
			{
				
				lub_counter_button=_0_ms;    /* Reset counter*/
				rub_State=BUTTON_AS_DOWN;
				
			}
			
			else 
			{
				//nothing
			}
		}
				
				
		else if((BUTTON_UP == B_ACTIVE) && (BUTTON_DOWN == B_INACTIVE) )
		{		
			
			lub_counter_button++;	             /*Increases counter to 10 milliseconds*/
			if(lub_counter_button>=_10_ms)
			{
				lub_counter_button=_0_ms;    /* Reset counter*/
				rub_State=BUTTON_AS_UP;
				
			}
			
			else
			{
				//nothing
			}
		}
				
		else
		{
			lub_counter_button=_0_ms;       /* Reset counter*/
		}
}





