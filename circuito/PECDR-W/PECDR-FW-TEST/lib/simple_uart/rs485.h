/**
 * rs485.h
 *
 *  @date Created at:	11/01/2024, 11:28:08
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

/* Includes ---------------------------------------------------------------------------------------------------------------------------------------------*/
#include <config.h>
#include "simple_uart.h"

#ifndef rs_485_H_
#define rs_485_H_

/* macro ------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Definition --------------------------------------------------------------------------------------------------------------------------------------------*/

void rs485_vSetup(  uint uart, uint baudrate, uint tx, uint rx  );

void rs458_vTxEnableRxDisable( void );
void rs458_vRxDisableTxEnable( void );
void rs458_vRxEnableTxDisable( void );
void rs458_vTxDisableRxEnable( void );

void rs458_vCleanBuffer( uint uart ) ;
size_t rs485_uGetBufferSize( uint uart ) ;
const char *rs485_pcGetBuffer( uint uart );

void rs485_vSendChar( uint uart, const char ch );
void rs485_vSendString(  uint uart, const char *str );
void rs485_vSendStringLn(  uint uart, const char *str );



#endif /* rs_485_H_ */
