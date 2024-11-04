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
#include <string.h>

#include "pico/stdlib.h"


#include "hardware.h"


#ifndef config_H_
#define config_H_

/* settings ----------------------------------------------------------------------------------------------------------------------------------------------*/
/* Definition --------------------------------------------------------------------------------------------------------------------------------------------*/


#define CONFIG_ENABLE			( 1			)
#define CONFIG_DISABLE			( 0			)


/* ************************************************************************************************************ */
/* CONFIGURAÇÕES DA INTERFACE SERIAL PRINCIPAL e SECUNDARIA							*/
/* ************************************************************************************************************ */
#define CONFIG_RS485_INTERFACE		(_idxUart0		)
#define CONFIG_BAUD_RATE_UART0		( 115200		)
#define CONFIG_DATA_BITS		( 8			)
#define CONFIG_STOP_BITS		( 1			)
#define CONFIG_PARITY			( UART_PARITY_NONE	)
#define CONFIG_BUFFER_SIZE		( 1024			)

/* ************************************************************************************************************ */
/* CONFIGURAÇÕES DO SERVO/BDESC MOTORES										*/
/* ************************************************************************************************************ */
#define CONFIG_MOROT_A			( CONFIG_DISABLE	)
#define CONFIG_MOROT_B			( CONFIG_ENABLE		)


#define CONFIG_PWM_FREQUENCY_HZ		( 400			)
#define CONFIG_PWM_DUTY_CYCLE_START	( 0			)
#define CONFIG_MOTOR_VELOCITY_MAX	( ( float ) 100.00 	)
#define CONFIG_KP			( 0.0300		)
#define CONFIG_KI			( 0.0009		)
#define CONFIG_KD			( 0.0002		)



/* ************************************************************************************************************ */
/* CONFIGURAÇÕES REDE												*/
/* ************************************************************************************************************ */


#endif /* config_H_ */
