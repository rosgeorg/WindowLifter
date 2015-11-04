/*
 * GPIO.h
 *
 *  Created on: Nov 1, 2015
 *      Author: PUG
 */
#include "typedefs.h"
#include "MPC5606B.h"


#ifndef GPIO_H_
#define GPIO_H_


#define on 0
#define off 1

/****GPIO's****/

#define LED1      0
#define LED2      1
#define LED3      2
#define LED4      3
#define LED5      4
#define LED6      5
#define LED7      6
#define LED8      7
#define LED9      8
#define LED10      9 
#define LED_UP    10
#define LED_DOWN  11


#define BUTTON1 64 /*S2*/
#define BUTTON2 65
#define BUTTON3 66
#define BUTTON4 67


/* Input Buttons */
#define BUTTON_UP        SIU.GPDI[BUTTON1].B.PDI
#define BUTTON_DOWN      SIU.GPDI[BUTTON2].B.PDI

#define ANTI_PINCH       SIU.GPDI[BUTTON4].B.PDI

#define B_ACTIVE                  0
#define B_INACTIVE                1



/** Set LED */ 
#define LED_ON(channel)                     (SIU.GPDO[channel].B.PDO =  on)
/** Clear LED */ 
#define LED_OFF(channel)                    (SIU.GPDO[channel].B.PDO =  off)
/** Toggle LED */ 
#define LED_TOGGLE(channel)                 (SIU.GPDO[channel].B.PDO ^= off) 




void GPIO_config(void);

#endif /* GPIO_H_ */
