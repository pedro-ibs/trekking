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
void uart_vHandlerRx( void );
/* Setup -------------------------------------------------------------------------------------------------------------------------------------------------*/
char pcUartBuffer[ CONFIG_BUFFER_SIZE ] = { 0 };
size_t uBufferSize			= 0;
/* -------------------------------------------------------------------------------------------------------------------------------------------------------*/


void uart_vSetup(void){
	int UART_IRQ = ( HARDWARE_UART_ID == uart0 ) ? ( UART0_IRQ ) : ( UART1_IRQ );

	uart_init(HARDWARE_UART_ID, CONFIG_BAUD_RATE);

	gpio_set_function(HARDWARE_TX_GPIO, GPIO_FUNC_UART);
    	gpio_set_function(HARDWARE_RX_GPIO, GPIO_FUNC_UART);
	uart_set_hw_flow(HARDWARE_UART_ID, false, false);
	uart_set_format(HARDWARE_UART_ID, CONFIG_DATA_BITS, CONFIG_STOP_BITS, CONFIG_PARITY);
	uart_set_fifo_enabled(HARDWARE_UART_ID, false);
	irq_set_exclusive_handler(UART_IRQ, uart_vHandlerRx);
	irq_set_enabled(UART_IRQ, true);
	uart_set_irq_enables(HARDWARE_UART_ID, true, false);

	uart_vCleanBuffer();
}

void uart_vCleanBuffer(void){
	
	uBufferSize = 0;

	for (size_t i = 0; i < CONFIG_BUFFER_SIZE; i++) {
		pcUartBuffer[i] = 0x00;
	}

}

size_t uart_uGetBufferSize(void){
	return uBufferSize;
}

const char *uart_pcGetBuffer(void){
	return pcUartBuffer;
}

void uart_vSendChar(char ch) {
	while( ! uart_is_writable( HARDWARE_UART_ID ) );
	uart_putc( HARDWARE_UART_ID, ch );
}

void uart_vSendString( const char *str ) {
	while( ! uart_is_writable( HARDWARE_UART_ID ) );
	uart_puts( HARDWARE_UART_ID, str );
}

void uart_vSendStringLn( const char *str ) {
	uart_vSendString(str);
	uart_vSendString("\r\n");
}





/*########################################################################################################################################################*/
/*########################################################################################################################################################*/
/*########################################################################################################################################################*/
/*-------------------------------------------------------------------- Local Functions -------------------------------------------------------------------*/
/*########################################################################################################################################################*/

void uart_vHandlerRx( void ) {
	while (uart_is_readable(HARDWARE_UART_ID)) {
		uint8_t ch = uart_getc(HARDWARE_UART_ID);

		if( uBufferSize > CONFIG_BUFFER_SIZE ){
			uBufferSize = 0;
			uart_vCleanBuffer();
		}

		pcUartBuffer[uBufferSize++] = ch;
	}
}