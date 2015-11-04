/*
 * GPIO.c
 *
 *  Created on: Nov 1, 2015
 *      Author: PUG
 */
#include "GPIO.h"


	


void GPIO_config(void)
{
	uint16_t lub_i;
  
    /* Set Port A as OUTPUT*/
  	for(lub_i=0;lub_i<12;lub_i++)
  	{
  		SIU.PCR[lub_i].R = 0x200;	
  	}
  	
  	SIU.GPDO[10].B.PDO = off;
  	SIU.GPDO[11].B.PDO = off;
  	
  	
  	/* Embedded board buttons */
  	SIU.PCR[BUTTON1].R = 0x100;	
  	SIU.PCR[BUTTON2].R = 0x100;
  	SIU.PCR[BUTTON3].R = 0x100;
  	SIU.PCR[BUTTON4].R = 0x100;	
}

