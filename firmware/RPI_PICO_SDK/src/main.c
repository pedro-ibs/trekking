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
#include <telemetry_power.h>
/* Setings -----------------------------------------------------------------------------------------------------------------------------------------------*/
/* Setup -------------------------------------------------------------------------------------------------------------------------------------------------*/
typedef struct {
	motor right1;
	motor right2;
	motor left1;
	motor left2;
	
} dataMotors;

typedef struct  {
	int motorRight1;
	int motorRight2;
	int motorLeft1;
	int motorLeft2;
} setpoint;



typedef struct {
	pid motorRight1;
	pid motorRight2;
	pid motorLeft1;
	pid motorLeft2;
} dataPIDs;

queue_t sendToCore0Queue;
queue_t sendToCore1Queue;

static float fGlobalPowerSupplyA	= 0.00;
static float fGlobalPowerSupplyB	= 0.00;
static float fGlobalPowerSystem		= 0.00;


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

	char buffer[ CONFIG_BUFFER_SIZE ]	= { 0		};
	setpoint velocities			= { 0, 0, 0, 0	};
	dataMotors motors			= { 0		};

	float fPowerSupplyA			= 0.00;
	float fPowerSupplyB			= 0.00;
	float fPowerSystem			= 0.00;
	uint count				= 0;

	/* base setup */
	stdio_init_all();
	uart_vSetup( _idxUart0, CONFIG_BAUD_RATE_UART0, HARDWARE_TX0_GPIO, HARDWARE_RX0_GPIO );
	uart_vSetup( _idxUart1, CONFIG_BAUD_RATE_UART0, HARDWARE_TX1_GPIO, HARDWARE_RX1_GPIO );

	telemetry_vSetup();

	/* multicore setup */
	queue_init( &sendToCore1Queue,	sizeof( setpoint	), CONFIG_QUEUE_ELEMENTS );
    	queue_init( &sendToCore0Queue,	sizeof( dataMotors	), CONFIG_QUEUE_ELEMENTS );
	multicore_launch_core1( core1_entry );

	/* set the first setpoint at core 1 */
	queue_add_blocking( &sendToCore1Queue, &velocities );

	/* show the first data */
	queue_remove_blocking( &sendToCore0Queue, &motors );
	textp_puCleanBlk( ( uint8_t* )buffer, CONFIG_BUFFER_SIZE );
	main_showInformation( &motors, buffer );


	while (true) {

		const char *pcBuffer = uart_pcGetBuffer( _idxUart0 );

		if ( textp_bFindString( pcBuffer, "\n" ) == true ) {

			if( textp_bGetLabelInfo( pcBuffer, "mr1", 0, buffer ) ){ 
				velocities.motorRight1	= atoi(buffer);
			}

			if( textp_bGetLabelInfo( pcBuffer, "mr2", 0, buffer ) ){
				velocities.motorRight2	= atoi(buffer);
			}

			if( textp_bGetLabelInfo( pcBuffer, "ml1", 0, buffer ) ){
				velocities.motorLeft1	= atoi(buffer);
			}

			if( textp_bGetLabelInfo( pcBuffer, "ml2", 0, buffer ) ){
				velocities.motorLeft2	= atoi(buffer);
			}

			queue_add_blocking( &sendToCore1Queue, &velocities );

			uart_vCleanBuffer( _idxUart0 );
		}


		if( queue_try_remove( &sendToCore0Queue, &motors ) == true ){
			textp_puCleanBlk( (uint8_t*)buffer, CONFIG_BUFFER_SIZE );
			main_showInformation( &motors, buffer );
		}


		count++;

		if (  count >= CONFIG_MOVING_AVERAGE ){

			fGlobalPowerSupplyA	= ( fPowerSupplyA	/ CONFIG_MOVING_AVERAGE ) + CONFIG_POWER_SUPPLY_OFFSET;
			fGlobalPowerSupplyB	= ( fPowerSupplyB	/ CONFIG_MOVING_AVERAGE ) + CONFIG_POWER_SUPPLY_OFFSET;
			fGlobalPowerSystem	= ( fPowerSystem	/ CONFIG_MOVING_AVERAGE ) + CONFIG_POWER_SYSTEM_OFFSET;
			
			fPowerSupplyA		= 0;
			fPowerSupplyB		= 0;
			fPowerSystem		= 0;

			count			= 0;

		} else {
			fPowerSupplyA		= fPowerSupplyA	+ telemetry_fGetPowerSupplyA();
			fPowerSupplyB		= fPowerSupplyB	+ telemetry_fGetPowerSupplyB();
			fPowerSystem		= fPowerSystem	+ telemetry_fGetPowerSystem();
		}

		sleep_ms( CONFIG_DELAY_LOOP_MS );

	}
}



void core1_entry( void )   {
	
	setpoint velocities = {0, 0, 0, 0};

	dataMotors motors = {
		.right1		= { HARDWARE_M1CHA_GPIO, HARDWARE_M1CHB_GPIO, 0, 0		},
		.right2		= { HARDWARE_M2CHA_GPIO, HARDWARE_M2CHB_GPIO, 0, 0		},
		.left1		= { HARDWARE_M4CHA_GPIO, HARDWARE_M4CHB_GPIO, 0, 0		},
		.left2		= { HARDWARE_M3CHA_GPIO, HARDWARE_M3CHB_GPIO, 0, 0		},
	};

	dataPIDs pids = {
		.motorRight1	= { CONFIG_KP, CONFIG_KI, CONFIG_KD, 0, 0, 0, 0, 0, 0, 0, 0, 0 	},
		.motorRight2	= { CONFIG_KP, CONFIG_KI, CONFIG_KD, 0, 0, 0, 0, 0, 0, 0, 0, 0 	},
		.motorLeft1	= { CONFIG_KP, CONFIG_KI, CONFIG_KD, 0, 0, 0, 0, 0, 0, 0, 0, 0 	},
		.motorLeft2	= { CONFIG_KP, CONFIG_KI, CONFIG_KD, 0, 0, 0, 0, 0, 0, 0, 0, 0 	}
	};


	motor_vSetup(&motors.right1,	CONFIG_PWM_FREQUENCY_HZ, CONFIG_PWM_DUTY_CYCLE_START);
	motor_vSetup(&motors.right2,	CONFIG_PWM_FREQUENCY_HZ, CONFIG_PWM_DUTY_CYCLE_START);
	motor_vSetup(&motors.left1,	CONFIG_PWM_FREQUENCY_HZ, CONFIG_PWM_DUTY_CYCLE_START);
	motor_vSetup(&motors.left2,	CONFIG_PWM_FREQUENCY_HZ, CONFIG_PWM_DUTY_CYCLE_START);


	queue_remove_blocking( &sendToCore1Queue, &velocities );

	// pids.motorRight1.fSetPoint	= velocities.motorRight1;
	// pids.motorRight2.fSetPoint	= velocities.motorRight2;
	// pids.motorLeft1.fSetPoint	= velocities.motorLeft1;
	// pids.motorLeft2.fSetPoint	= velocities.motorLeft2;

	motors.right1.pwm	= velocities.motorRight1;
	motors.right2.pwm	= velocities.motorRight2;
	motors.left1.pwm	= velocities.motorLeft1;
	motors.left2.pwm	= velocities.motorLeft2;

	while (true) {

		queue_try_add(&sendToCore0Queue, &motors);

		if( queue_try_remove(&sendToCore1Queue, &velocities) == true ){
			// pids.motorRight1.fSetPoint	= velocities.motorRight1;
			// pids.motorRight2.fSetPoint	= velocities.motorRight2;
			// pids.motorLeft1.fSetPoint	= velocities.motorLeft1;
			// pids.motorLeft2.fSetPoint	= velocities.motorLeft2;
		}

		motor_vMove(&motors.right1,	velocities.motorRight1	); 
		motor_vMove(&motors.right2,	velocities.motorRight2	); 
		motor_vMove(&motors.left1,	velocities.motorLeft1	); 
		motor_vMove(&motors.left2,	velocities.motorLeft2	); 

		
		sleep_ms( CONFIG_PID_FRAME_HATE_MS );		
	}

}

void main_showInformation( const dataMotors *motors, char *buffer ){

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

		fGlobalPowerSupplyA,
		fGlobalPowerSupplyB,
		fGlobalPowerSystem
	);

	uart_vSendStringLn(_idxUart0, buffer);
	uart_vSendStringLn(_idxUart1, buffer);

}