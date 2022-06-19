/**
 * config.h
 *
 *  @date Created at:	16/06/2022 17:45:43
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
 * Configurações gerais do sistema e aplicação
 *
 */

/* Includes ---------------------------------------------------------------------------------------------------------------------------------------------*/
#include "hardware.h"
#include <zephyr.h>

#ifndef config_H_
#define config_H_

/* settings ----------------------------------------------------------------------------------------------------------------------------------------------*/
/* Definition --------------------------------------------------------------------------------------------------------------------------------------------*/


#endif /* config_H_ */



/* ************************************************************************************************************ */
/* CONFIGURAÇÕES DA COMUNICAÇÃO SERIAL comm.h 									*/
/* ************************************************************************************************************ */
#define UART_MESSAGE_SIZE		( 204		)
#define UART_QUEUE_SIZE			( 10		)
#define UART_TIMEOUT			( K_MSEC(200)	)
#define UART_END_MESSAGE		( ';'		)

