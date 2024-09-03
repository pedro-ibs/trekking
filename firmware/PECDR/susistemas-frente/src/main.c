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

typedef enum {
	_Stop,
	_Front,
	_Back,
} Direction ;

typedef struct  {
	
	float		velocity;
	Direction	direction;

} Motor;

typedef struct  {
	
	Motor ma;
	Motor mb;

} MotorGroup;
/* Setup -------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Function prototype ------------------------------------------------------------------------------------------------------------------------------------*/
void core1_entry( void );
Motor readCommand( const char *pcReceiverBuffer, const char * commandStop, const char * commandToBack, const char * commandToFront  );
/* -------------------------------------------------------------------------------------------------------------------------------------------------------*/



int main( void ) {


	/* base setup */
	stdio_init_all();

	gpio_init	( HARDWARE_LED_GPIO				);
	gpio_set_dir	( HARDWARE_LED_GPIO,		GPIO_OUT	);

	rs485_vSetup( CONFIG_RS485_INTERFACE, CONFIG_BAUD_RATE_UART0, HARDWARE_TX0_GPIO, HARDWARE_RX0_GPIO );


	rs458_vCleanBuffer( CONFIG_RS485_INTERFACE );
	rs458_vRxEnableTxDisable();

	const char * pcReceiverBuffer = rs485_pcGetBuffer( CONFIG_RS485_INTERFACE );

	queue_init( &sendToCore1Queue,	sizeof( MotorGroup ), 5 );
	multicore_launch_core1( core1_entry );

	gpio_put( HARDWARE_LED_GPIO, true );
	
	while (true) {

		if( rs485_uGetBufferSize( CONFIG_RS485_INTERFACE ) > 0 ){
			
			gpio_put( HARDWARE_LED_GPIO, false );

			sleep_ms( 10 );


			MotorGroup mg = {
				.ma = readCommand( pcReceiverBuffer, "MAS", "MAB", "MAF"  ),
				.mb = readCommand( pcReceiverBuffer, "MBS", "MBB", "MBF"  )
			};

			queue_add_blocking( &sendToCore1Queue, &mg );

			rs458_vCleanBuffer( CONFIG_RS485_INTERFACE );

			gpio_put( HARDWARE_LED_GPIO, true );

		}
	}
}



void core1_entry( void ){
	
	#if( CONFIG_MOROT_FRONT == CONFIG_ENABLE  )
	servo motorDriverA = { HARDWARE_MOTOR2_GPIO, 0 }; 
	servo motorDriverB = { HARDWARE_MOTOR1_GPIO, 0 }; 
	#endif

	#if( CONFIG_MOROT_BACK == CONFIG_ENABLE  )
	servo motorDriverA = { HARDWARE_MOTOR1_GPIO, 0 }; 
	servo motorDriverB = { HARDWARE_MOTOR2_GPIO, 0 }; 
	#endif

	#if( CONFIG_MOROT_FRONT == CONFIG_ENABLE  )
	sleep_ms( 3000 ); 

	motor_vBind( &motorDriverA );

	sleep_ms( 1000 ); 

	motor_vBind( &motorDriverB );

	sleep_ms( 1000 );
	#endif

	#if( CONFIG_MOROT_BACK == CONFIG_ENABLE  )
	sleep_ms( 5000 ); 

	motor_vBind( &motorDriverA );

	sleep_ms( 3000 ); 

	motor_vBind( &motorDriverB );

	sleep_ms( 1000 );
	#endif

	MotorGroup mg = { 0x00 };
	Direction currentDirectionMotorA = _Stop;
	Direction currentDirectionMotorB = _Stop;

	pid pid_ma = {
		.fKp = CONFIG_KP,
		.fKi = CONFIG_KI,
		.fKd = CONFIG_KD,
	};

	pid pid_mb = {
		.fKp = CONFIG_KP,
		.fKi = CONFIG_KI,
		.fKd = CONFIG_KD,
	};

	#if( CONFIG_MOROT_FRONT == CONFIG_ENABLE  )
	rs485_vSendStringLn( CONFIG_RS485_INTERFACE, "SUBSYS-FRONT-OK");
	#endif

	#if( CONFIG_MOROT_BACK == CONFIG_ENABLE  )
	rs485_vSendStringLn( CONFIG_RS485_INTERFACE, "SUBSYS-BACK-OK");
	#endif

	while ( true ) {

		if( queue_try_remove(&sendToCore1Queue, &mg) == true ){

			if( currentDirectionMotorA != mg.ma.direction ){
				currentDirectionMotorA = mg.ma.direction;

				if( currentDirectionMotorA == _Stop ){
					motor_vPreoareToBack( &motorDriverA );
				}

				pid_ma.fInput = mg.ma.velocity;

			}

			if( currentDirectionMotorB != mg.mb.direction ){
				currentDirectionMotorB = mg.mb.direction;

				if( currentDirectionMotorB == _Stop ){
					motor_vPreoareToBack( &motorDriverB );
				}

				pid_mb.fInput = mg.mb.velocity;

			}			
		}

		switch ( currentDirectionMotorA ) {
			case _Stop: {
				motor_vStop( &motorDriverA );
			} break;
			case _Front: {
				motor_vToFront( &motorDriverA, pid_ma.fOutput );
			} break;
			case _Back: {
				motor_vToBack( &motorDriverA, pid_ma.fOutput );
			} break;
		}

		switch ( currentDirectionMotorB ) {
			case _Stop: {
				motor_vStop( &motorDriverB );
			} break;
			case _Front: {
				motor_vToFront( &motorDriverB, pid_mb.fOutput );
			} break;
			case _Back: {
				motor_vToBack( &motorDriverB, pid_mb.fOutput );
			} break;
		}

		pid_ma.fInput =  pid_fRun( &pid_ma );
		pid_mb.fInput =  pid_fRun( &pid_mb );

		sleep_ms( 1 );

	}
	
}



Motor readCommand( const char *pcReceiverBuffer, const char * commandStop, const char * commandToBack, const char * commandToFront  ){

	char pcBuffer[ 100 ]	= { 0x00 };
	
	Motor motor = { 
		.velocity = 0,
		.direction = _Stop
	};

	if ( textp_bFindString (pcReceiverBuffer, commandStop ) == true ){

		motor.velocity = 0;
		motor.direction = _Stop;

	} else if ( textp_bGetLabelInfo (pcReceiverBuffer, commandToBack, 0, pcBuffer ) == true ){

		motor.velocity = atoff( pcBuffer );
		motor.direction = _Back;

	} else if ( textp_bGetLabelInfo (pcReceiverBuffer, commandToFront, 0, pcBuffer ) == true ){

		motor.velocity = atoff( pcBuffer );
		motor.direction = _Front;

	}

	if( motor.velocity <= 0 ){
		motor.velocity = 0;
		motor.direction = _Stop;
	}

	return motor;
}