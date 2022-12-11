/**
 * config.h
 *
 *  @date Created at:	07/08/2022 14:00:24
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
 * Configurações gerais da aplicação
 * 
 */

/* Includes ---------------------------------------------------------------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stddef.h>
#include <ctype.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware.h"


#ifndef config_H_
#define config_H_

/* settings ----------------------------------------------------------------------------------------------------------------------------------------------*/
/* Definition --------------------------------------------------------------------------------------------------------------------------------------------*/


/* ************************************************************************************************************ */
/* CONFIGURAÇÕES DA INTERFACE SERIAL PRINCIPAL. 								*/
/* ************************************************************************************************************ */
#define CONFIG_BAUD_RATE		( 115200		)
#define CONFIG_DATA_BITS		( 8			)
#define CONFIG_STOP_BITS		( 1			)
#define CONFIG_PARITY			( UART_PARITY_NONE	)
#define CONFIG_BUFFER_SIZE		( 1024			)


/* ************************************************************************************************************ */
/* CONFIGURAÇÕES DA TELEMETRIA DA FONTE DE ALIMENTAÇÃO.								*/
/* ************************************************************************************************************ */
#define CONFIG_TELEMETRY_CLOCK_DIV	( 960			)						// 52 Hz




/* ************************************************************************************************************ */
/* CONFIGURAÇÕES DO DRIVERS MOTORES										*/
/* ************************************************************************************************************ */
#define CONFIG_PWM_SYS_FREQUENCY_HZ	( 125000000		)
#define CONFIG_PWM_FREQUENCY_HZ		( 400			)
#define CONFIG_PWM_DUTY_CYCLE_START	( 0			)
#define CONFIG_KP			( 0.0751		)
#define CONFIG_KI			( 0.0009		)
#define CONFIG_KD			( 0.0003		)
#define CONFIG_PID_FRAME_HATE_MS	( 1			)

/* ************************************************************************************************************ */
/* FORMATO DE COMUNICAÇÃO JSON (PARA FACILITAR NO NODE-RED)							*/
/* ************************************************************************************************************ */
#define CONFIG_JSON "{\"ml1\":{\"s\":%d, \"m\":%d,\"v\":%f},\"ml2\":{\"s\":%d,\"m\":%d,\"v\":%f},\"mr1\":{\"s\":%d,\"m\":%d,\"v\":%f},\"mr2\":{\"s\":%d,\"m\":%d,\"v\":%f},\"p\":{\"i\":%f,\"c\":%f,\"s\":%f,\"a\":%f}}"			


/* ************************************************************************************************************ */
/* Configurações gerais da aplicação										*/
/* ************************************************************************************************************ */
#define CONFIG_QUEUE_ELEMENTS 		( 1			)


#endif /* config_H_ */
