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



#define _0_ms                       0
#define _10_ms                      10
#define _500_ms                     500
#define _400_ms                     400
#define _5_s                        5000
#define CLOSED                      0 	
#define OPEN                        10


 



void window_up(void);
void window_down(void);
void up(void);
void down(void);
void button_as_up(void);
void button_as_down(void);
void aintipinch(void);
void relax_5_seconds(void);

extern void State_Machine(void);




#endif /* WINDOW_LIFTER_H_ */
