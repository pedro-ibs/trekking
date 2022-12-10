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
#include <pico/multicore.h>
#include <pico/util/queue.h>
#include <simple_uart.h>
#include <textProtocol.h>
#include <motor.h> 
#include <pid.h> 
/* Setings -----------------------------------------------------------------------------------------------------------------------------------------------*/
/* Setup -------------------------------------------------------------------------------------------------------------------------------------------------*/
typedef struct {
	motor right1;
	motor right2;
	motor left1;
	motor left2;
} dataMotors;

typedef struct {
	pid motorRight1;
	pid motorRight2;
	pid motorLeft1;
	pid motorLeft2;
} dataPIDs;

queue_t sendToCore0Queue;
queue_t sendToCore1queue;


/* Function prototype ------------------------------------------------------------------------------------------------------------------------------------*/
void main_showInformation(const dataMotors *motors, char *buffer);
void core1_entry( void );
/* -------------------------------------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief the main is pined at core 0, this core are dedicated to communication between devices
 * both queue be pinned at core 0 too, so, send and receive queue there are in "function main"
 * perspective 
 */
int main( void ) {

	dataMotors motors  = {
		.right1		= { HARDWARE_M1CHA_GPIO, HARDWARE_M1CHB_GPIO, 0, 0 },
		.right2		= { HARDWARE_M2CHA_GPIO, HARDWARE_M2CHB_GPIO, 0, 0 },
		.left1		= { HARDWARE_M4CHA_GPIO, HARDWARE_M4CHB_GPIO, 0, 0 },
		.left2		= { HARDWARE_M3CHA_GPIO, HARDWARE_M3CHB_GPIO, 0, 0 }	
	};

	char buffer[ CONFIG_BUFFER_SIZE ] = { 0 };

	/* base setup */
	stdio_init_all();
	uart_vSetup();

	/* show the starting values */
	main_showInformation(&motors, buffer);
	sleep_ms(1000);

	/* multicore setup */
	queue_init(&sendToCore1queue,	sizeof(dataMotors), CONFIG_QUEUE_ELEMENTS);
    	queue_init(&sendToCore0Queue,	sizeof(dataMotors), CONFIG_QUEUE_ELEMENTS);
	multicore_launch_core1(core1_entry);

	queue_add_blocking(&sendToCore1queue, &motors);

	while (true) {

		if( queue_try_remove(&sendToCore0Queue, &motors) == true ){
			textp_puCleanBlk((uint8_t*)buffer, CONFIG_BUFFER_SIZE);
			main_showInformation(&motors, buffer);
			sleep_ms(50);
		} else {
			sleep_ms(5);
		}
	}
}



void core1_entry( void )   {
	
	dataMotors motors  = { };
	queue_remove_blocking(&sendToCore1queue, &motors);

	dataPIDs pids  = {
		.motorRight1	= { CONFIG_KP, CONFIG_KI, CONFIG_KD, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		.motorRight2	= { CONFIG_KP, CONFIG_KI, CONFIG_KD, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		.motorLeft1	= { CONFIG_KP, CONFIG_KI, CONFIG_KD, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		.motorLeft2	= { CONFIG_KP, CONFIG_KI, CONFIG_KD, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
	};

	motor_vSetup(&motors.right1,	CONFIG_PWM_FREQUENCY_HZ, CONFIG_PWM_DUTY_CYCLE_START);
	motor_vSetup(&motors.right2,	CONFIG_PWM_FREQUENCY_HZ, CONFIG_PWM_DUTY_CYCLE_START);
	motor_vSetup(&motors.left1,	CONFIG_PWM_FREQUENCY_HZ, CONFIG_PWM_DUTY_CYCLE_START);
	motor_vSetup(&motors.left2,	CONFIG_PWM_FREQUENCY_HZ, CONFIG_PWM_DUTY_CYCLE_START);


	uint32_t set_point =  motors.right1.pwm_max - 1;

	while (true) {

		queue_try_add(&sendToCore0Queue, &motors);

		// if( queue_try_remove(&sendToCore1Queue, &motors) == true ){

		// }



		pids.motorRight1.fSetPoint 	= set_point;
		pids.motorRight1.fInput		= motors.right1.pwm;

		set_point -= 2;
		if ( set_point < 50){
			set_point = motors.right1.pwm_max-1;
		}

		motor_vToFront(&motors.right1,	pid_fRun(&pids.motorRight1)	);

		sleep_ms( CONFIG_PID_FRAME_HATE_MS );

	}

}







void main_showInformation(const dataMotors *motors, char *buffer){

	sprintf( buffer, CONFIG_JSON,
		motors->left1.pwm,
		motors->left1.pwm_max,
		0.0,

		motors->left2.pwm,
		motors->left2.pwm_max,
		0.0,

		motors->right1.pwm,
		motors->right1.pwm_max,
		0.0,

		motors->right2.pwm,
		motors->right2.pwm_max,
		0.0,

		0.0,
		0.0,
		0.0,
		0.0
	);

	uart_vSendStringLn(buffer);
}