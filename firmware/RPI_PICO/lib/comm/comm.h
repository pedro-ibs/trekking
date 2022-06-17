/**
 * comm.h
 *
 *  @date Created at:	16/06/2022 17:13:42
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
#include <zephyr.h>


#ifndef comm_H_
#define comm_H_

/* settings ----------------------------------------------------------------------------------------------------------------------------------------------*/

typedef enum{
	UART0 = 0,
	UART1,
	UART_QTY
} uart_device;

/* Definition --------------------------------------------------------------------------------------------------------------------------------------------*/

void comm_vSetup(void);
void comm_vGetMessage(uart_device dev, char *msg, k_timeout_t timeout);
void comm_uSendChar( uart_device dev, char c );
void comm_uSendString( uart_device dev, const char *str );
void comm_uSendStringLn( uart_device dev, const char *str );

#endif /* comm_H_ */
