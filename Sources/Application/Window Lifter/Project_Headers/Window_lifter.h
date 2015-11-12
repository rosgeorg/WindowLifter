/*
 * Window_lifter.h
 *
 *  Created on: Nov 2, 2015
 *      Author: PUG
 */

#ifndef WINDOW_LIFTER_H_
#define WINDOW_LIFTER_H_

#include "GPIO.h"
#include "typedefs.h"
#include "MPC5606B.h"
#include "Button.h"
#include "LED.h"



#define _0_ms                       0
#define _10_ms                      10
#define _500_ms                     500
#define _400_ms                     400
#define _5_s                        5000
#define CLOSED                      9 	
#define OPEN                        0


 



void automatic_up(void);
void automatic_down(void);
void manual_up(void);
void manual_down(void);
void button_as_up(void);
void button_as_down(void);
void aintipinch(void);
void lock_wl(void);

extern void State_Machine();




#endif /* WINDOW_LIFTER_H_ */
