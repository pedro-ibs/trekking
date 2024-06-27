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

#include <config.h>
#include <rs485.h>
/* Setings -----------------------------------------------------------------------------------------------------------------------------------------------*/
/* Setup -------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Function prototype ------------------------------------------------------------------------------------------------------------------------------------*/
/* -------------------------------------------------------------------------------------------------------------------------------------------------------*/


void loopMain( void ){

		rs485_vSendString( _idxUart0, "dasdahkdhsja_turnon_djdsnfmdsnfsdf" );
		// cyw43_arch_gpio_put( HARDWARE_LED_GPIO,	true );
		gpio_put( HARDWARE_LED_GPIO,	true );
		gpio_put( HARDWARE_M1CHA_GPIO,	true );
		gpio_put( HARDWARE_M1CHB_GPIO,	true );
		gpio_put( HARDWARE_M2CHA_GPIO,	true );
		gpio_put( HARDWARE_M2CHB_GPIO,	true );
		sleep_ms( 500 );

		rs485_vSendString( _idxUart0, "dasdahkdhsja_turnoff_djdsnfmdsnfsdf" );
		// cyw43_arch_gpio_put( HARDWARE_LED_GPIO,	false );
		gpio_put( HARDWARE_LED_GPIO,	false );
		gpio_put( HARDWARE_M1CHA_GPIO,	false );
		gpio_put( HARDWARE_M1CHB_GPIO,	false );
		gpio_put( HARDWARE_M2CHA_GPIO,	false );
		gpio_put( HARDWARE_M2CHB_GPIO,	false );
		sleep_ms( 500 );

}

void loopSec( void ){

		if( rs485_uGetBufferSize( _idxUart0 ) > 0 ){
			sleep_ms( 20 );


			if( strstr( rs485_pcGetBuffer( _idxUart0 ), "turnon" ) != NULL ){
				// cyw43_arch_gpio_put( HARDWARE_LED_GPIO,	true );
				gpio_put( HARDWARE_LED_GPIO,	true );
				gpio_put( HARDWARE_M1CHA_GPIO,	true );
				gpio_put( HARDWARE_M1CHB_GPIO,	true );
				gpio_put( HARDWARE_M2CHA_GPIO,	true );
				gpio_put( HARDWARE_M2CHB_GPIO,	true );
			}

			if( strstr( rs485_pcGetBuffer( _idxUart0 ), "turnoff" ) != NULL ){
				// cyw43_arch_gpio_put( HARDWARE_LED_GPIO,	false );
				gpio_put( HARDWARE_LED_GPIO,	false );
				gpio_put( HARDWARE_M1CHA_GPIO,	false );
				gpio_put( HARDWARE_M1CHB_GPIO,	false );
				gpio_put( HARDWARE_M2CHA_GPIO,	false );
				gpio_put( HARDWARE_M2CHB_GPIO,	false );
			}
				
			rs458_vCleanBuffer( _idxUart0 );
			rs458_vRxEnableTxDisable();
		}

		sleep_ms( 1 );
}

int main( void ) {

	/* base setup */
	stdio_init_all();

	// if (cyw43_arch_init()) {
	// 	printf("Wi-Fi init failed");
	// 	return -1;
	// }

	rs485_vSetup( _idxUart0, CONFIG_BAUD_RATE_UART0, HARDWARE_TX0_GPIO, HARDWARE_RX0_GPIO );

	gpio_init	( HARDWARE_LED_GPIO				);
	gpio_set_dir	( HARDWARE_LED_GPIO,		GPIO_OUT	);
	
	gpio_init	( HARDWARE_M1CHA_GPIO				);
	gpio_set_dir	( HARDWARE_M1CHA_GPIO,		GPIO_OUT	);

	gpio_init	( HARDWARE_M1CHB_GPIO				);
	gpio_set_dir	( HARDWARE_M1CHB_GPIO,		GPIO_OUT	);

	gpio_init	( HARDWARE_M2CHA_GPIO				);
	gpio_set_dir	( HARDWARE_M2CHA_GPIO,		GPIO_OUT	);

	gpio_init	( HARDWARE_M2CHB_GPIO				);
	gpio_set_dir	( HARDWARE_M2CHB_GPIO,		GPIO_OUT	);

	gpio_init	( HARDWARE_TXRX_ENABLE_GPIO			);
	gpio_set_dir	( HARDWARE_TXRX_ENABLE_GPIO,	GPIO_OUT	);


	gpio_put( HARDWARE_LED_GPIO,	true );

	rs485_vSendString( _idxUart0, "startrd\r\n" );
	rs458_vCleanBuffer( _idxUart0 );
	rs458_vRxEnableTxDisable();


	while (true) {
		loopSec();
		// loopMain();
	}
}

/*########################################################################################################################################################*/
/*########################################################################################################################################################*/
/*########################################################################################################################################################*/
/*--------------------------------------------------------------------- Local Functions ------------------------------------------------------------------*/
/*########################################################################################################################################################*/


