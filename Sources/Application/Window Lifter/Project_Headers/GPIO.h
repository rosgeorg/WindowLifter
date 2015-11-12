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


#define on 1
#define off 0



#define BUTTON1 64 /*S2*/
#define BUTTON2 65
#define BUTTON3 66



/* Input Buttons */
#define BUTTON_UP        SIU.GPDI[BUTTON1].B.PDI
#define BUTTON_DOWN      SIU.GPDI[BUTTON2].B.PDI

#define ANTI_PINCH       SIU.GPDI[BUTTON3].B.PDI

#define B_ACTIVE                  1
#define B_INACTIVE                0








void GPIO_config(void);

#endif /* GPIO_H_ */
