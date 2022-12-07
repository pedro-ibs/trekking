/**
 * simple_uart.c
 *
 *  @date Created at:	07/08/2022 10:50:05
 *	@author:	Pedro Igor B. S.
 *	@email:		pedro.igor.ifsp@gmail.com
 * 	GitHub:		https://github.com/pedro-ibs
 * 	tabSize:	8
 *
 * #######################################################################
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
 * #######################################################################
 *
 *
 * TODO: documentation or resume or Abstract
 *
 */



/* Includes ----------------------------------------------------------------------------------------------------------------------------------------------*/
#include <config.h>
#include <simple_uart.h>
#include <textProtocol.h>
#include <motor.h> 
#include <pid.h> 
/* Setings -----------------------------------------------------------------------------------------------------------------------------------------------*/
/* Function prototype ------------------------------------------------------------------------------------------------------------------------------------*/
void main_showInformation(void);
/* Setup -------------------------------------------------------------------------------------------------------------------------------------------------*/
static motor motorRight1	= { HARDWARE_M1CHA_GPIO, HARDWARE_M1CHB_GPIO, 0, 0};
static motor motorRight2	= { HARDWARE_M2CHA_GPIO, HARDWARE_M2CHB_GPIO, 0, 0};
static motor motorLeft1		= { HARDWARE_M4CHA_GPIO, HARDWARE_M4CHB_GPIO, 0, 0};
static motor motorLeft2		= { HARDWARE_M3CHA_GPIO, HARDWARE_M3CHB_GPIO, 0, 0};

static pid pid_motorRight1	= { CONFIG_KP, CONFIG_KI, CONFIG_KD, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
static pid pid_motorRight2	= { CONFIG_KP, CONFIG_KI, CONFIG_KD, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
static pid pid_motorLeft1	= { CONFIG_KP, CONFIG_KI, CONFIG_KD, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
static pid pid_motorLeft2	= { CONFIG_KP, CONFIG_KI, CONFIG_KD, 0, 0, 0, 0, 0, 0, 0, 0, 0 };


static char buffer[CONFIG_BUFFER_SIZE]	= "";
/* -------------------------------------------------------------------------------------------------------------------------------------------------------*/

int main( void ) {

	stdio_init_all();

	motor_vSetup(&motorRight1,	CONFIG_PWM_FREQUENCY_HZ, CONFIG_PWM_DUTY_CYCLE_START);
	motor_vSetup(&motorRight2,	CONFIG_PWM_FREQUENCY_HZ, CONFIG_PWM_DUTY_CYCLE_START);
	motor_vSetup(&motorLeft1,	CONFIG_PWM_FREQUENCY_HZ, CONFIG_PWM_DUTY_CYCLE_START);
	motor_vSetup(&motorLeft2,	CONFIG_PWM_FREQUENCY_HZ, CONFIG_PWM_DUTY_CYCLE_START);

	pid_motorRight1.fSetPoint	= motorRight1.pwm_max	/ 2;
	pid_motorRight2.fSetPoint	= motorRight2.pwm_max	/ 2;
	pid_motorLeft1.fSetPoint	= motorLeft1.pwm_max	/ 2;
	pid_motorLeft2.fSetPoint	= motorLeft2.pwm_max 	/ 2;

	uart_vSetup();

	sleep_ms(1000);

	main_showInformation();

	uint32_t set_point =  motorRight1.pwm_max;

	while (true) {

		pid_motorRight1.fSetPoint 	= set_point;
		pid_motorRight1.fInput		= motorRight1.pwm;

		set_point -= 25;
		if ( set_point < 50){
			set_point = motorRight1.pwm_max-1;
		}

		motor_vToFront(&motorRight1,	pid_fRun(&pid_motorRight1)	);

		main_showInformation();
		sleep_ms(25);
	}
}



void main_showInformation(void){

	textp_puCleanBlk((uint8_t*)buffer, CONFIG_BUFFER_SIZE);

	sprintf( buffer, CONFIG_JSON,
		motorLeft1.pwm,
		motorLeft1.pwm_max,
		0.0,

		motorLeft2.pwm,
		motorLeft2.pwm_max,
		0.0,

		motorRight1.pwm,
		motorRight1.pwm_max,
		0.0,

		motorRight2.pwm,
		motorRight2.pwm_max,
		0.0,

		0.0,
		0.0,
		0.0,
		0.0
	);

	uart_vSendStringLn(buffer);
}