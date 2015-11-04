/*
 * Window_Lifter.c
 *
 *  Created on: Nov 3, 2015
 *      Author: PUG
 */

#include "Window_lifter.h"





uint16_t rub_LED_Position=LED1;
uint16_t ruw_time_button=_0_ms, ruw_time_transition=_0_ms;

uint16_t rub_State=LWEAKNESS;





void State_Machine(void)
{
	
	
	switch(rub_State)
	{
		case LWEAKNESS:
			button_signal();     
			break;
			
		
		case UP:
			up();
			break;
			
			
		case DOWN:
			down();
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
			
		case RELAX_5_SECONDS:
			relax_5_seconds();
			break;
	}  
	
}       








/**************************************************************/
void window_down(void)
{
	if(BUTTON_UP == B_ACTIVE)
	{
		LED_OFF(LED_DOWN);
		rub_State=	UP;
		ruw_time_button=_0_ms;
	}    
	
	else
	{
		ruw_time_transition++;
		if((ruw_time_transition==_400_ms) && (rub_LED_Position<=LED10))
		{
			LED_ON(LED_DOWN);
			LED_OFF(rub_LED_Position);
			rub_LED_Position++;
			ruw_time_transition=_0_ms;
		}
		
		else
		{
			//nothing
		}
			
		if(rub_LED_Position==OPEN)
		{
			rub_State=LWEAKNESS;
			rub_LED_Position=LED10;
			ruw_time_button=_0_ms	;
			LED_OFF(LED_DOWN);
		}
		
		else
		{
			//nothing
		}
	}   	
	
}  
/*************** End function window_down ***************/


/**************************************************************/
void window_up(void)
{	
	if(ANTI_PINCH==B_ACTIVE)
	{
		ruw_time_button=_0_ms;
		rub_State=ANTIPINCH;	
	} 
	
	else
	{	
		if(BUTTON_DOWN == B_ACTIVE)
		{
			LED_OFF(LED_UP);
			rub_State=DOWN;
			ruw_time_button=_0_ms;
		}    
	
		else
		{
			ruw_time_transition++;
			if((ruw_time_transition==_400_ms) && (rub_LED_Position>=LED1))
			{
				LED_ON(LED_UP);
				LED_ON(rub_LED_Position);
				rub_LED_Position--;
				ruw_time_transition=_0_ms;
			}
			
			else
			{
				//nothing
			}
			
			if(rub_LED_Position==CLOSED)
			{
				rub_State=LWEAKNESS;
				rub_LED_Position=LED1;
				ruw_time_button=_0_ms;
				LED_OFF(LED_UP);
			}	
			
			else
			{
				//nothing
			}
		}
	}
	
}  /*************** End function window_up ***************/


/**************************************************************/

void up(void)
{
		if((BUTTON_UP == B_ACTIVE) || (BUTTON_DOWN == B_ACTIVE))
	{
			window_up();
	}
			
	else
	{
		ruw_time_button=_0_ms;
		rub_State=LWEAKNESS;	
		LED_OFF(LED_UP);	
	}	
}   /*************** End function manual_up ***************/



/**************************************************************/

void down(void)
{
	
						
	if((BUTTON_DOWN == B_ACTIVE) || (BUTTON_UP == B_ACTIVE))
	{
		window_down();
	}
			
	else
	{
		ruw_time_button=_0_ms;
		rub_State=LWEAKNESS;	
		LED_OFF(LED_DOWN);	
	}
}    /*************** End function manual_down ***************/

/**************************************************************/

void button_as_up(void)
{
	if(BUTTON_UP == B_ACTIVE)
	{
		ruw_time_button++;
		if((ruw_time_button>_500_ms) && (BUTTON_UP == B_ACTIVE))
		{
				
			
			rub_State=UP;
		}
		
		else
		{
			//nothing
		}
	}
	
	else
	{
		window_up();	
	}
			
}   /*************** End function automatic_up_action ***************/



/**************************************************************/

void button_as_down(void)
{
	
		
	if(BUTTON_DOWN == B_ACTIVE)
	{
		
		ruw_time_button++;
		if((ruw_time_button >  _500_ms) && (BUTTON_DOWN == B_ACTIVE))
		{
			
			rub_State=DOWN;
		}
		
		else
		{
			
			//nothing
		}
	}
	
	else
	{
		
		window_down();	
	}
}  /*************** End function automatic_down_action ***************/

/**************************************************************/

void aintipinch(void)
{
	ruw_time_button++;	       
	if(ruw_time_button>=_10_ms)
	{
		ruw_time_transition++;
		if((ruw_time_transition==_400_ms) && (rub_LED_Position<=LED10))
		{
			LED_OFF(LED_UP);
			LED_ON(LED_DOWN);
			LED_OFF(rub_LED_Position);
			rub_LED_Position--;
			ruw_time_transition=_0_ms;
		}
			
		if(rub_LED_Position==OPEN)
		{
			rub_LED_Position=LED1;
			ruw_time_button=_0_ms;
			LED_OFF(LED_DOWN);
			rub_State=RELAX_5_SECONDS;
		}
	}
}   /*************** End function antipinch ***************/


/**************************************************************/

void relax_5_seconds(void)
{
	static uint8_t luw_time_RELAX;
	luw_time_RELAX++;
	if(luw_time_RELAX==_5_s)
	{
		luw_time_RELAX=_0_ms;
		rub_State=LWEAKNESS;
	}
}   /**************** End function relax_5_seconds ***************/

