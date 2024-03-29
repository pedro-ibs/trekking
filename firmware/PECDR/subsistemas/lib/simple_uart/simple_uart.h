/**
 * simple_uart.h
 *
 *  @date Created at:	07/08/2022 10:49:42
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

/* Includes ---------------------------------------------------------------------------------------------------------------------------------------------*/
#include <config.h>


#ifndef simple_uart_H_
#define simple_uart_H_

/* settings ----------------------------------------------------------------------------------------------------------------------------------------------*/
/* Definition --------------------------------------------------------------------------------------------------------------------------------------------*/

typedef enum {
	_idxUart0 = 0,
	_idxUart1,
} uart_index;


void uart_vSetup( uint uart, uint baudrate, uint tx, uint rx );

void uart_vCleanBuffer( uint uart );
size_t uart_uGetBufferSize( uint uart );
const char *uart_pcGetBuffer( uint uart );

void uart_vSendChar( uint uart, const char ch) ;
void uart_vSendString( uint uart, const char *str ) ;
void uart_vSendStringLn( uint uart, const char *str ) ;


#endif /* simple_uart_H_ */
