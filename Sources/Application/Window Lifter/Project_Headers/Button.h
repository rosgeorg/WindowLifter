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



 enum ESTATUS
{
	LWEAKNESS ,
	UP,
	DOWN,
	BUTTON_AS_UP,
	BUTTON_AS_DOWN,
	ANTIPINCH,
	RELAX_5_SECONDS
};


extern void button_signal (void);


#endif /* BUTTON_H_ */
