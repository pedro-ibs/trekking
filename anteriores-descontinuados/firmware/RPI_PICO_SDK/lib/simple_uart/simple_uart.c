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
#include "simple_uart.h"
#include "hardware/uart.h"
#include "hardware/irq.h"
#include <config.h>
#include <hardware.h>
/* Setings -----------------------------------------------------------------------------------------------------------------------------------------------*/
/* Function prototype ------------------------------------------------------------------------------------------------------------------------------------*/
void uart_vHandlerRx0( void );
void uart_vHandlerRx1( void );
void uart_vHandler_( uint uart );
/* Setup -------------------------------------------------------------------------------------------------------------------------------------------------*/

typedef struct  {
	uart_inst_t 	*id;

	uint		irq;

	void 		*handler;

	char 		buffer[ CONFIG_BUFFER_SIZE ];
	size_t 		size;
} simple_uart;

simple_uart xUart[] = {
	{ uart0, UART0_IRQ, uart_vHandlerRx0, "", 0 },
	{ uart1, UART1_IRQ, uart_vHandlerRx1, "", 0 }
};

/* -------------------------------------------------------------------------------------------------------------------------------------------------------*/


void uart_vSetup( uint uart, uint baudrate, uint tx, uint rx ){
	
	uart_init( xUart[ uart ].id, baudrate );
	gpio_set_function( tx, GPIO_FUNC_UART );
    	gpio_set_function( rx, GPIO_FUNC_UART );
	uart_set_hw_flow( xUart[ uart ].id, false, false );
	uart_set_format( xUart[ uart ].id, CONFIG_DATA_BITS, CONFIG_STOP_BITS, CONFIG_PARITY );
	uart_set_fifo_enabled(  xUart[ uart ].id, false );
	irq_set_exclusive_handler( xUart[ uart ].irq, xUart[ uart ].handler );
	irq_set_enabled( xUart[ uart ].irq, true );
	uart_set_irq_enables( xUart[ uart ].id, true, false );
	

	uart_vCleanBuffer( uart );
}

void uart_vCleanBuffer( uint uart ){

	xUart[ uart ].size = 0;

	for (size_t i = 0; i < CONFIG_BUFFER_SIZE; i++) {
		xUart[ uart ].buffer[ i ] = 0x00;
	}

}

size_t uart_uGetBufferSize( uint uart ){
	return xUart[ uart ].size;
}

const char *uart_pcGetBuffer( uint uart ){
	return xUart[ uart ].buffer;
}

void uart_vSendChar( uint uart, const char ch) {
	while( ! uart_is_writable( xUart[ uart ].id ) );
	uart_putc( xUart[ uart ].id, ch );
}

void uart_vSendString( uint uart, const char *str ) {
	while( ! uart_is_writable( xUart[ uart ].id ) );
	uart_puts( xUart[ uart ].id, str );
}

void uart_vSendStringLn( uint uart, const char *str ) {
	uart_vSendString( uart, str );
	uart_vSendString( uart, "\r\n" );
}





/*########################################################################################################################################################*/
/*########################################################################################################################################################*/
/*########################################################################################################################################################*/
/*-------------------------------------------------------------------- Local Functions -------------------------------------------------------------------*/
/*########################################################################################################################################################*/


void uart_vHandler_( uint uart ){
	while ( uart_is_readable( xUart[ uart ].id ) ) {
		uint8_t ch = uart_getc( xUart[ uart ].id );

		if( xUart[ uart ].size > CONFIG_BUFFER_SIZE ){
			uart_vCleanBuffer( uart );
		}

		xUart[ uart ].buffer[ xUart[ uart ].size++ ] = ch;
	}	
}



void uart_vHandlerRx0( void ) {

	uart_vHandler_( _idxUart0 );

}


void uart_vHandlerRx1( void ) {

	uart_vHandler_( _idxUart1 );

}
