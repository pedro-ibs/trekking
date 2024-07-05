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
 * 
 * 
 *
 */



/* Includes ----------------------------------------------------------------------------------------------------------------------------------------------*/
#include <pico/stdlib.h>

#include <config.h>
#include <rs485.h>
#include <textProtocol.h>

#include <servo.h>

/* Setings -----------------------------------------------------------------------------------------------------------------------------------------------*/
/* Setup -------------------------------------------------------------------------------------------------------------------------------------------------*/
static servo s_v = { HARDWARE_SERVO_V_GPIO, 0 }; 
static servo s_h = { HARDWARE_SERVO_H_GPIO, 0 }; 

/* Function prototype ------------------------------------------------------------------------------------------------------------------------------------*/
void core1_entry( void );
/* -------------------------------------------------------------------------------------------------------------------------------------------------------*/



int main( void ) {



	/* base setup */
	stdio_init_all();

	cyw43_arch_init();

	gpio_init	( HARDWARE_P1CHA_GPIO			);
	gpio_init	( HARDWARE_P1CHB_GPIO			);
	gpio_init	( HARDWARE_P2CHA_GPIO			);
	gpio_init	( HARDWARE_P2CHB_GPIO			);
	
	gpio_set_dir	( HARDWARE_P1CHA_GPIO,	GPIO_OUT	);
	gpio_set_dir	( HARDWARE_P1CHB_GPIO,	GPIO_OUT	);
	gpio_set_dir	( HARDWARE_P2CHA_GPIO,	GPIO_OUT	);
	gpio_set_dir	( HARDWARE_P2CHB_GPIO,	GPIO_OUT	);


	gpio_set_dir	( HARDWARE_P1CHA_GPIO,	GPIO_OUT	);
	gpio_set_dir	( HARDWARE_P1CHB_GPIO,	GPIO_OUT	);
	gpio_set_dir	( HARDWARE_P2CHA_GPIO,	GPIO_OUT	);
	gpio_set_dir	( HARDWARE_P2CHB_GPIO,	GPIO_OUT	);

	gpio_put	( HARDWARE_P1CHA_GPIO, false		 );
	gpio_put	( HARDWARE_P1CHB_GPIO, false		 );
	gpio_put	( HARDWARE_P2CHA_GPIO, false		 );
	gpio_put	( HARDWARE_P2CHB_GPIO, false		 );

	servo_vInit( &s_v );
	servo_vInit( &s_h );


	rs485_vSetup( CONFIG_RS485_INTERFACE, CONFIG_BAUD_RATE_UART0, HARDWARE_TX0_GPIO, HARDWARE_RX0_GPIO );

	sleep_ms( 1000 );


	cyw43_arch_gpio_put( HARDWARE_LED_GPIO,	true );

	rs458_vCleanBuffer( CONFIG_RS485_INTERFACE );
	rs485_vSendString( CONFIG_RS485_INTERFACE, "voyager-check-rs485" );
	rs458_vRxEnableTxDisable();
	const char * pcReceiverBuffer = rs485_pcGetBuffer( CONFIG_RS485_INTERFACE );

	/* posicionar camera para fente */
	// servo_vWriteAngle( &s_h, 90 );
	// servo_vWriteAngle( &s_v, 90 );


	while (true) {

		if( rs485_uGetBufferSize( CONFIG_RS485_INTERFACE ) > 0 ){
			
			cyw43_arch_gpio_put( HARDWARE_LED_GPIO,	false );

			sleep_ms( 10 );

			char pcBuffer[ 100 ] = "";

			if ( textp_bGetLabelInfo (pcReceiverBuffer, "FPV", 0, pcBuffer ) == true){
				bool level = atoi( pcBuffer );
				gpio_put ( HARDWARE_P2CHA_GPIO, level		 );
				gpio_put ( HARDWARE_P2CHB_GPIO, level		 );
			}

			if ( textp_bGetLabelInfo (pcReceiverBuffer, "FPV", 1, pcBuffer ) == true){
				uint16_t value = atoi( pcBuffer );
				servo_vWriteAngle( &s_v, value );
			}

			if ( textp_bGetLabelInfo (pcReceiverBuffer, "FPV", 2, pcBuffer ) == true){
				uint16_t value = atoi( pcBuffer );
				servo_vWriteAngle( &s_h, value );
			}


			if ( textp_bGetLabelInfo (pcReceiverBuffer, "BZZ", 0, pcBuffer ) == true){
				bool level = atoi( pcBuffer );
				gpio_put ( HARDWARE_P1CHA_GPIO, level		 );
				gpio_put ( HARDWARE_P1CHB_GPIO, true		 );
			}

			rs458_vCleanBuffer( CONFIG_RS485_INTERFACE );

			cyw43_arch_gpio_put( HARDWARE_LED_GPIO,	true );



		}				
		
	}
}



void core1_entry( void )   {


	while (true) {
		sleep_ms( 1000 );
	}
	
}
