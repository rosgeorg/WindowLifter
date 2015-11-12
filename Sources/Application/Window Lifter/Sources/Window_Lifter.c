/*
 * Window_Lifter.c
 *
 *  Created on: Nov 3, 2015
 *      Author: PUG
 */

#include "Window_lifter.h"





uint16_t rub_LED_Position=LED10;
uint16_t ruw_time_button=_0_ms, ruw_time_transition=_0_ms;
uint8_t auto_val;
uint16_t rub_State=LWEAKNESS;





void State_Machine(void)
{
	
	
	switch(rub_State)
	{
		case LWEAKNESS:
			button_validation();     
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
	if(BUTTON_UP)
	{
		auto_val=1;
	}
	else if (BUTTON_DOWN)
	{
		rub_State=LWEAKNESS;
	}
	if(PIT.CH[0].TFLG.B.TIF == 1)
	{
		ruw_time_transition++;
		PIT.CH[0].TFLG.B.TIF = 1; //Limpiar la bandera, w1c
		if((auto_val == 1) && (ruw_time_transition==_400_ms))
		{
			LED_ON(rub_LED_Position); //Prender el led correspondiente a Led_Position
			rub_LED_Position++;
			if(rub_LED_Position > 9)
			{
				rub_LED_Position = 9;
				auto_val = 0;
				rub_State=LWEAKNESS;
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
		SIU.PCR[68].R = 0x200;
		SIU.GPDO[68].B.PDO=0;
		auto_val=2;
		
	ruw_time_transition++;
	
		if((auto_val == 2) && (ruw_time_transition==_400_ms))
		{
			LED_OFF(rub_LED_Position); //Apagar el led correspondiente a Led_Position
			rub_LED_Position--;
			if(rub_LED_Position == 0)
			{
				rub_LED_Position = 0;
				auto_val = 0;
				rub_State = LWEAKNESS;
			}
		}
	}
}
	

/*************** End function automatic_down ***************/

/**************************************************************/

void manual_up(void)
{

if(PIT.CH[0].TFLG.B.TIF == 1)
{
	ruw_time_transition++;
	if(ruw_time_transition == _400_ms)	
	{
		PIT.CH[0].TFLG.B.TIF = 1; //Limpiar la bandera, w1c
		if(BUTTON_UP)
		{
			LED_ON(rub_LED_Position); //Turns on LED based on variable "Led_Position"
			rub_LED_Position++;
			if(rub_LED_Position >= 9)
			{
				rub_LED_Position = 9;
				rub_State = LWEAKNESS;
			}
		 }
		else
		{
			rub_State = LWEAKNESS;
		}
	}
}
}


/*************** End function manual_up ***************/

/**************************************************************/

void manual_down(void)
{
	if(BUTTON_UP == B_ACTIVE)
		{
			LED_OFF(LED_DOWN);
			rub_State=BUTTON_AS_UP;
			ruw_time_button=_0_ms;
		}    
	
	else
	{
		
	ruw_time_transition++;
		if(ruw_time_transition == _400_ms)
		{

			if(BUTTON_DOWN == B_ACTIVE)
			{
							
				LED_OFF(rub_LED_Position); //Turns off LED based on variable "Led_Position"
				rub_LED_Position--;
				ruw_time_transition=_0_ms;
				
				if(rub_LED_Position == 0)
				{
					rub_LED_Position = 0;
					rub_State = LWEAKNESS;
				}
			 }
			else 
			{
				rub_State = LWEAKNESS;	
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
	
	if(PIT.CH[0].TFLG.B.TIF == 1)
	{
		ruw_time_button++;
		if(ruw_time_button>_500_ms)
		{
							
			rub_State=MANUAL_UP;
		}
		
		else if(ruw_time_button<_500_ms)
		{
			rub_State=AUTOMATIC_UP;
		}
	}
	
}  

/*************** End function automatic_up_action ***************/



/**************************************************************/

void button_as_down(void)
{
	LED_ON(LED_DOWN);
	LED_OFF(LED_UP);

	if(BUTTON_DOWN == B_ACTIVE)						
	{		ruw_time_button++;
		if((ruw_time_button >=_500_ms) && (BUTTON_DOWN==B_ACTIVE))
		{
			
			rub_State=MANUAL_DOWN;
		}
		else
		{
			//nothing
		}
		
		
	}
	else
		{
		SIU.PCR[69].R = 0x200;
												SIU.GPDO[69].B.PDO=0;
			rub_State=AUTOMATIC_DOWN;
		
		}
		
}
/*************** End function automatic_down_action ***************/

/**************************************************************/

void aintipinch(void)
{
	ruw_time_button++;	       
	if(ruw_time_button>=_10_ms)
	{
		if(PIT.CH[0].TFLG.B.TIF == 1)
			{	 
				ruw_time_transition++;
				PIT.CH[0].TFLG.B.TIF = 1;
				LED_OFF(LED_UP);
				LED_ON(LED_DOWN);
						if(ruw_time_transition==_400_ms)
						{
						
							LED_OFF(rub_LED_Position);
							rub_LED_Position--;
							ruw_time_transition=_0_ms;
							if(rub_LED_Position <= 0)
										{
										rub_LED_Position = 0;
											rub_State = LOCK_WL;
										}
							
						}
							
		}
	}
}
/*************** End function antipinch ***************/


/**************************************************************/

void lock_wl(void)
{
	static uint8_t luw_time_LOCK;
	luw_time_LOCK++;
	if(luw_time_LOCK==_5_s)
	{
		luw_time_LOCK=_0_ms;
		rub_State=LWEAKNESS;
	}
}   


/**************** End function relax_5_seconds ***************/

