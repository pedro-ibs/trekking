/**
 * rs485.c
 *
 *  @date Created at:	11/01/2024, 11:27:57
 *	@author:	Pedro Igor B. S.
 *	@email:		pibscontato@gmail.com
 * 	GitHub:		https://github.com/pedro-ibs
 * 	tabSize:	8
 *
 * ########################################################
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
 * ########################################################
 *
 * TODO: documentation or resume or Abstract
 *
 */



/* Includes ----------------------------------------------------------------------------------------------------------------------------------------------*/
#include "rs485.h"
#include "simple_uart.h"
#include "hardware/uart.h"
#include "hardware/irq.h"
#include <config.h>
#include <hardware.h>
/* Setings -----------------------------------------------------------------------------------------------------------------------------------------------*/
#define DELAY_ENABLE_DISABLE_TRANSITION	( 1 )  // this is important for RS485 working
/* Setup -------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Function prototype ------------------------------------------------------------------------------------------------------------------------------------*/
/* -------------------------------------------------------------------------------------------------------------------------------------------------------*/

void rs485_vSetup(  uint uart, uint baudrate, uint tx, uint rx  ) {

	gpio_init	( HARDWARE_TXRX_ENABLE_GPIO			);
	gpio_set_dir	( HARDWARE_TXRX_ENABLE_GPIO,	GPIO_OUT	);

	gpio_put( HARDWARE_TXRX_ENABLE_GPIO, HARDWARE_TX_ENABLE_RX_DISABLE );

	uart_vSetup( uart, baudrate, tx, rx  );

	rs458_vRxEnableTxDisable();
}


void rs458_vTxEnableRxDisable( void ){
	gpio_put( HARDWARE_TXRX_ENABLE_GPIO, HARDWARE_TX_ENABLE_RX_DISABLE );
	sleep_ms( DELAY_ENABLE_DISABLE_TRANSITION );
}

void rs458_vRxDisableTxEnable( void ){
	gpio_put( HARDWARE_TXRX_ENABLE_GPIO, HARDWARE_TX_ENABLE_RX_DISABLE );
	sleep_ms( DELAY_ENABLE_DISABLE_TRANSITION );

}

void rs458_vRxEnableTxDisable( void ){
	sleep_ms( DELAY_ENABLE_DISABLE_TRANSITION );
	gpio_put( HARDWARE_TXRX_ENABLE_GPIO, HARDWARE_RX_ENABLE_TX_DISABLE );

}

void rs458_vTxDisableRxEnable( void ){
	sleep_ms( DELAY_ENABLE_DISABLE_TRANSITION );
	gpio_put( HARDWARE_TXRX_ENABLE_GPIO, HARDWARE_RX_ENABLE_TX_DISABLE );

}


void rs458_vCleanBuffer( uint uart ) {
	uart_vCleanBuffer( uart );
}

size_t rs485_uGetBufferSize( uint uart ) {
	return uart_uGetBufferSize( uart );
}


const char *rs485_pcGetBuffer( uint uart ){
	return uart_pcGetBuffer( uart );
}


void rs485_vSendChar( uint uart, const char ch) {
	rs458_vTxEnableRxDisable();
	uart_vSendChar(uart, ch);
	rs458_vTxDisableRxEnable();
}

void rs485_vSendString( uint uart, const char *str ) {
	rs458_vTxEnableRxDisable();
	uart_vSendString( uart, str );
	rs458_vTxDisableRxEnable();
}

void rs485_vSendStringLn( uint uart, const char *str ) {
	rs458_vTxEnableRxDisable();
	uart_vSendString( uart, str );
	uart_vSendString( uart, "\r\n" );
	rs458_vTxDisableRxEnable();
}


/*########################################################################################################################################################*/
/*########################################################################################################################################################*/
/*########################################################################################################################################################*/
/*--------------------------------------------------------------------- Local Functions ------------------------------------------------------------------*/
/*########################################################################################################################################################*/

