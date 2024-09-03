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
typedef enum {
	_Stop =0,
	_Front,
	_Back,
} Direction ;

typedef struct  {
	
	float velocity;
	Direction direction;

} Motor;

typedef struct {
	Motor ma;
	Motor mb;
} MotorGroup ;

/* Function prototype ------------------------------------------------------------------------------------------------------------------------------------*/
void core1_entry( void );
bool readCommand( const char *pcReceiverBuffer, Motor *motor, const char * commandStop, const char * commandToBack, const char * commandToFront  );
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


	const char maToFront[  ]	= "MAF";
	const char maToBack[  ]		= "MAB";
	const char maStop[  ]		= "MAS";

	const char mbToFront[  ]	= "MBF";
	const char mbToBack[  ]		= "MBB";
	const char mbStop[  ]		= "MBS";
	
	while (true) {

		if( rs485_uGetBufferSize( CONFIG_RS485_INTERFACE ) > 0 ){
			
			gpio_put( HARDWARE_LED_GPIO, false );

			sleep_ms( 10 );
			
			Motor ma = { 0x00 };
			Motor mb = { 0x00 };


			readCommand( pcReceiverBuffer, &ma, "MAS", "MAB", "MAF" );
			readCommand( pcReceiverBuffer, &mb, "MBS", "MBB", "MBF" );

			if( ma.velocity <= 0 ){
				ma.velocity = 0;
				ma.direction = _Stop;
			}	

			if( mb.velocity <= 0 ){
				mb.velocity = 0;
				mb.direction = _Stop;
			}

			MotorGroup mg = { ma, mb };
			
			queue_add_blocking( &sendToCore1Queue, &mg );

			rs458_vCleanBuffer( CONFIG_RS485_INTERFACE );

			gpio_put( HARDWARE_LED_GPIO, true );

		}
	}
}



void core1_entry( void ){
	servo motorA = { HARDWARE_MOTOR1_GPIO, 0 }; 
	servo motorB = { HARDWARE_MOTOR2_GPIO, 0 }; 


	#if( CONFIG_MOROT_FRENTE == CONFIG_ENABLE  )
	sleep_ms( 3000 ); 

	motor_vBind( &motorA );

	sleep_ms( 1000 ); 

	motor_vBind( &motorB );

	sleep_ms( 1000 );
	#endif

	#if( CONFIG_MOROT_TRAS == CONFIG_ENABLE  )
	sleep_ms( 5000 ); 

	motor_vBind( &motor1 );

	sleep_ms( 3000 ); 

	motor_vBind( &motor2 );

	sleep_ms( 1000 );
	#endif

	MotorGroup mg = { 0x00 };
	Direction currentDirection = _Stop;

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

	#if( CONFIG_MOROT_FRENTE == CONFIG_ENABLE  )
	rs485_vSendStringLn( CONFIG_RS485_INTERFACE, "FRENTE-OK" );
	#endif

	#if( CONFIG_MOROT_TRAS == CONFIG_ENABLE  )
	rs485_vSendStringLn( CONFIG_RS485_INTERFACE, "TRAS-OK" );
	#endif

	while ( true ) {

		if( queue_try_remove( &sendToCore1Queue, &mg ) == true ){
			pid_ma.fSetPoint = mg.ma.velocity;
			pid_mb.fSetPoint = mg.mb.velocity;

			if(  currentDirection != mg.ma.direction ){				
				currentDirection = mg.ma.direction;
				if( currentDirection == _Back ){
					motor_vPreoareToBack( &motorA );
					motor_vPreoareToBack( &motorB );
				}
			}
		}

		switch ( currentDirection ) {

			case _Stop: {
				motor_vStop( &motorA );
				motor_vStop( &motorB );
			} break;

			case _Front: {
				motor_vToFront( &motorA, pid_ma.fOutput );
				motor_vToFront( &motorB, pid_mb.fOutput );
			} break;

			case _Back: {
				motor_vToBack( &motorA, pid_ma.fOutput );
				motor_vToBack( &motorB, pid_mb.fOutput );
			} break;

		}

		pid_ma.fInput =  pid_fRun( &pid_ma );
		pid_mb.fInput =  pid_fRun( &pid_mb );

		sleep_ms( 1 );

	}
	
}

bool readCommand( const char *pcReceiverBuffer, Motor *motor, const char * commandStop, const char * commandToBack, const char * commandToFront  ){

	char pcBuffer[ 100 ] = { 0x00 };

	if ( textp_bGetLabelInfo ( pcReceiverBuffer, commandStop, 0, pcBuffer ) == true ){
		motor->velocity		= 0;
		motor->direction	= _Stop;
		return true;
	}
	
	if( textp_bGetLabelInfo ( pcReceiverBuffer, commandToBack, 0, pcBuffer ) == true ){
		motor->velocity		= atoff(pcBuffer);
		motor->direction	= _Back;
		return true;
	}
	
	if( textp_bGetLabelInfo ( pcReceiverBuffer, commandToFront, 0, pcBuffer ) == true ){
		motor->velocity		= atoff(pcBuffer);
		motor->direction	= _Front;
		return true;
	}

	return false;
}