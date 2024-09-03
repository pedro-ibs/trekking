/**
 * motor.c
 *
 *  @date Created at:	02/07/2024, 21:19:56
 *	@author:	Pedro Igor B. S.
 *	@email:		pibscontato@gmail.com
 * 	GitHub:		https://github.com/pedro-ibs
 * 	tabSize:	8
 *
 * ########################################################
 *   Copyright (C) Pedro Igor B. S 2021
 * -------------------------------------------------------------------
 *
 *   Licença: GNU GPL 2
 * -------------------------------------------------------------------
 *   This program is free software; you can redistribute it and/or
 *   modify it under the terms of the GNU General Public License as
 *   published by the Free Software Foundation; version 2 of the
 *   License.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 * -------------------------------------------------------------------
 * ########################################################
 *
 * Baseado em:
 * 	https://github.com/pedro-ibs/bdesc-s10e-rtr-example-control/tree/main
 * 
 * Controle dos motores utilizando o bdesc-s10e-rtr
 *
 */




/* Includes ----------------------------------------------------------------------------------------------------------------------------------------------*/
#include "motor.h"

#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/time.h"

/* Setings -----------------------------------------------------------------------------------------------------------------------------------------------*/
#define MOTOR_STOP				( 1500							)
#define MOTOR_CLOCKWISE_MIN			( 1600							)
#define MOTOR_CLOCKWISE_MAX			( 1900							)
#define MOTOR_CLOCKWISE_RANGE			( MOTOR_CLOCKWISE_MAX - MOTOR_CLOCKWISE_MIN		)
#define MOTOR_ANTICLOCKWISE_MIN			( 1400							)
#define MOTOR_ANTICLOCKWISE_MAX			( 1000							)
#define MOTOR_ANTICLOCKWISE_RANGE		( MOTOR_ANTICLOCKWISE_MIN - MOTOR_ANTICLOCKWISE_MAX	)
#define STEP_DELAY_FOR_ANTICLOCKWISE		( 100							)
/* Setup -------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Function prototype ------------------------------------------------------------------------------------------------------------------------------------*/
/* -------------------------------------------------------------------------------------------------------------------------------------------------------*/

void motor_vBind( servo *motor ){

	servo_vInit( motor );

	servo_vWritePulse( motor, MOTOR_STOP );
	sleep_ms( 200 );

}


void motor_vToFront( servo *motor,  float v ){

	v = MOTOR_CLOCKWISE_MIN + ( v / CONFIG_MOTOR_VELOCITY_MAX ) * MOTOR_CLOCKWISE_RANGE;

	if( v >  MOTOR_CLOCKWISE_MAX ) v = MOTOR_CLOCKWISE_MAX;

	servo_vWritePulse(  motor, v );
};


void motor_vPreoareToBack( servo *motor ){

	servo_vWritePulse(  motor, MOTOR_STOP );
	sleep_ms( STEP_DELAY_FOR_ANTICLOCKWISE );

	servo_vWritePulse(  motor, MOTOR_ANTICLOCKWISE_MAX );
	sleep_ms( STEP_DELAY_FOR_ANTICLOCKWISE / 2 );

	servo_vWritePulse(  motor, MOTOR_STOP );
	sleep_ms( STEP_DELAY_FOR_ANTICLOCKWISE );
}


void motor_vToBack( servo *motor,  float v ){


	v = MOTOR_ANTICLOCKWISE_MIN -  ( v / CONFIG_MOTOR_VELOCITY_MAX ) * MOTOR_ANTICLOCKWISE_RANGE;

	if( v <  MOTOR_ANTICLOCKWISE_MAX ) v = MOTOR_ANTICLOCKWISE_MAX;

	servo_vWritePulse(  motor, v );
}


void motor_vStop( servo *motor ){

	servo_vWritePulse(  motor, MOTOR_STOP );

}




/*########################################################################################################################################################*/
/*########################################################################################################################################################*/
/*########################################################################################################################################################*/
/*--------------------------------------------------------------------- Local Functions ------------------------------------------------------------------*/
/*########################################################################################################################################################*/
