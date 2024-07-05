/**
 * hardware.h
 *
 *  @date Created at:	07/08/2022 14:03:26
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
 * As definições de hardware  utilizada na aplicação
 *
 */

/* Includes ---------------------------------------------------------------------------------------------------------------------------------------------*/
#include "pico/stdlib.h"

#ifndef hardware_H_
#define hardware_H_

/* settings ----------------------------------------------------------------------------------------------------------------------------------------------*/
/* Definition --------------------------------------------------------------------------------------------------------------------------------------------*/


/**
 * Comunicação serial raspberry - rpi_pico
 */
#define HARDWARE_UART0_ID		uart0
#define HARDWARE_TX0_GPIO		( 16				) 
#define HARDWARE_RX0_GPIO		( 17				)

#define HARDWARE_TXRX_ENABLE_GPIO	( 18				)
#define HARDWARE_RX_ENABLE_TX_DISABLE	( false				)
#define HARDWARE_TX_ENABLE_RX_DISABLE	( true				)

#define HARDWARE_LED_GPIO_RPI		( PICO_DEFAULT_LED_PIN		)
#define HARDWARE_LED_GPIO_RPIW		( CYW43_WL_GPIO_LED_PIN		)


#define HARDWARE_LED_GPIO               ( HARDWARE_LED_GPIO_RPIW	)



/**
 * Pinos utilizados nos motores
 */
#define HARDWARE_P1CHA_GPIO		( 22				)
#define HARDWARE_P1CHB_GPIO		( 21				)
#define HARDWARE_P2CHA_GPIO		( 20				)
#define HARDWARE_P2CHB_GPIO		( 19				)


#define HARDWARE_SERVO_H_GPIO		( 13				)
#define HARDWARE_SERVO_V_GPIO		( 11				)



#endif /* hardware_H_ */
