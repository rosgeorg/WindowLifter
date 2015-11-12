/*
 * PIT.h
 *
 *  Created on: Nov 1, 2015
 *      Author: PUG
 */

#ifndef PIT_H_
#define PIT_H_
#include    "typedefs.h"
#include    "MPC5606B.h"

#define    PITCHANNEL_0					0


#define    DEVICE_FREQUENCY           (uint32_t)64000000
#define    CHANNEL_DESIRED_FREQUENCY   (uint32_t)1000

/** Interrupt Timer macros */
#define    PIT_FREQUENCY_VALUE            	( ( DEVICE_FREQUENCY / CHANNEL_DESIRED_FREQUENCY ) - 1 )





void PIT_device_init(void);

/* PIT channel configuration */
void PIT_channel_config(uint8_t channel);

/** PIT Start procedure */
void PIT_channel_active(uint8_t channel);

/** PIT Low level Stop procedure */
void PIT_channel_stop(uint8_t channel);

/** PIT Channel 0 ISR  */
void PIT_channel0_ISR(void);


#endif /* PIT_H_ */
