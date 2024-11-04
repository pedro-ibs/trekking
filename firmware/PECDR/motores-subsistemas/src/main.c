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
#include <pico/stdlib.h>
#include <pico/multicore.h>
#include <pico/util/queue.h>

#include <textProtocol.h>
#include <config.h>
#include <rs485.h>
#include <servo.h>
#include <motor.h>
#include <pid.h>

/* Setings -----------------------------------------------------------------------------------------------------------------------------------------------*/
queue_t sendToCore1Queue;
/* Setup -------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Function prototype ------------------------------------------------------------------------------------------------------------------------------------*/
void core1_entry( void );
/* -------------------------------------------------------------------------------------------------------------------------------------------------------*/

typedef enum {
	_Stop =0,
	_Front,
	_Back,
} Direction ;

typedef struct  {
	
	float		velocity;
	Direction	direction;

} Motor;


int main( void ) {


	/* base setup */
	stdio_init_all();

	gpio_init	( HARDWARE_LED_GPIO				);
	gpio_set_dir	( HARDWARE_LED_GPIO,		GPIO_OUT	);

	rs485_vSetup( CONFIG_RS485_INTERFACE, CONFIG_BAUD_RATE_UART0, HARDWARE_TX0_GPIO, HARDWARE_RX0_GPIO );


	rs458_vCleanBuffer( CONFIG_RS485_INTERFACE );
	rs458_vRxEnableTxDisable();

	const char * pcReceiverBuffer = rs485_pcGetBuffer( CONFIG_RS485_INTERFACE );

	queue_init( &sendToCore1Queue,	sizeof( Motor ), 5 );
	multicore_launch_core1( core1_entry );

	gpio_put( HARDWARE_LED_GPIO, true );


	#if( CONFIG_MOROT_A == CONFIG_ENABLE  )
	const char commandToFront[  ]	= "MAF";
	const char commandToBack[  ]	= "MAB";
	const char commandStop[  ]	= "MAS";
	#endif

	#if( CONFIG_MOROT_B == CONFIG_ENABLE  )
	const char commandToFront[  ]	= "MBF";
	const char commandToBack[  ]	= "MBB";
	const char commandStop[  ]	= "MBS";
	#endif

	
	while (true) {

		if( rs485_uGetBufferSize( CONFIG_RS485_INTERFACE ) > 0 ){
			
			gpio_put( HARDWARE_LED_GPIO, false );

			sleep_ms( 10 );

			char pcBuffer[ 100 ] = "";

			if ( textp_bFindString (pcReceiverBuffer, commandStop ) == true ){
				
				Motor motor = { 0,  _Stop };

				queue_add_blocking( &sendToCore1Queue, &motor );

			} else if ( textp_bGetLabelInfo (pcReceiverBuffer, commandToBack, 0, pcBuffer ) == true ){
				
				Motor motor = { atoff( pcBuffer ), _Back };
				
				if( motor.velocity <= 0 ){
					motor.velocity = 0;
					motor.direction = _Stop;
				}
				
				queue_add_blocking( &sendToCore1Queue, &motor );

			} else if ( textp_bGetLabelInfo (pcReceiverBuffer, commandToFront, 0, pcBuffer ) == true ){
				Motor motor = { atoff( pcBuffer ), _Front };

				if( motor.velocity <= 0 ){
					motor.velocity = 0;
					motor.direction = _Stop;
				}

				queue_add_blocking( &sendToCore1Queue, &motor );
			}


			rs458_vCleanBuffer( CONFIG_RS485_INTERFACE );

			gpio_put( HARDWARE_LED_GPIO, true );

		}
	}
}


void core1_entry( void ){
	servo motor1 = { HARDWARE_MOTOR1_GPIO, 0 }; 
	servo motor2 = { HARDWARE_MOTOR2_GPIO, 0 }; 


	#if( CONFIG_MOROT_A == CONFIG_ENABLE  )
	sleep_ms( 3000 ); 
	motor_vBind( &motor1 );
	sleep_ms( 1000 ); 
	motor_vBind( &motor2 );
	sleep_ms( 1000 );
	#endif

	#if( CONFIG_MOROT_B == CONFIG_ENABLE  )
	sleep_ms( 6000 ); 
	motor_vBind( &motor1 );
	sleep_ms( 1000 ); 
	motor_vBind( &motor2 );
	sleep_ms( 1000 );
	#endif

	Motor motor;
	Direction currentDirection = _Stop;

	pid pid_ma1 = {
		.fKp = CONFIG_KP,
		.fKi = CONFIG_KI,
		.fKd = CONFIG_KD,
	};

	pid pid_ma2 = {
		.fKp = CONFIG_KP,
		.fKi = CONFIG_KI,
		.fKd = CONFIG_KD,
	};

	while ( true ) {

		if( queue_try_remove(&sendToCore1Queue, &motor) == true ){
			pid_ma1.fSetPoint = motor.velocity;
			pid_ma2.fSetPoint = motor.velocity;

			if(  currentDirection != motor.direction ){
				
				currentDirection = motor.direction;

				if( currentDirection == _Back ){
					motor_vPreoareToBack( &motor1 );
					motor_vPreoareToBack( &motor2 );
				}
			}


		}

		switch ( currentDirection ) {
			case _Stop: {
				motor_vStop( &motor1 );
				motor_vStop( &motor2 );
			} break;

			case _Front: {
				motor_vToFront( &motor1, pid_ma1.fOutput );
				motor_vToFront( &motor2, pid_ma2.fOutput );
			} break;

			case _Back: {
				motor_vToBack( &motor1, pid_ma1.fOutput );
				motor_vToBack( &motor2, pid_ma2.fOutput );
			} break;

		}

		pid_ma1.fInput =  pid_fRun( &pid_ma1 );
		pid_ma2.fInput =  pid_fRun( &pid_ma2 );

		sleep_ms( 1 );

	}
	
}