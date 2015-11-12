/*
 * Button.h
 *
 *  Created on: Nov 2, 2015
 *      Author: PUG
 */

#ifndef BUTTON_H_
#define BUTTON_H_

#define _0_ms         0
#define _10_ms        10

#include "GPIO.h"
#include "typedefs.h"
#include "MPC5606B.h"
#include "Window_lifter.h"
#include "LED.h"


 enum ESTATUS
{
	LWEAKNESS ,
	AUTOMATIC_UP,
	AUTOMATIC_DOWN,
	MANUAL_UP,
	MANUAL_DOWN,
	BUTTON_AS_UP,
	BUTTON_AS_DOWN,
	ANTIPINCH,
	LOCK_WL
};


extern void button_validation (void);


#endif /* BUTTON_H_ */
