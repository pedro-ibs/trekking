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
#define HARDWARE_UART_ID		uart0
#define HARDWARE_TX_GPIO		( 0	) 
#define HARDWARE_RX_GPIO		( 1	)

#define HARDWARE_LED_GPIO               ( PICO_DEFAULT_LED_PIN	)


/**
 * Pinos utilizados nos motores
 */
#define HARDWARE_M1CHA_GPIO		( 12	)
#define HARDWARE_M1CHB_GPIO		( 13	)
#define HARDWARE_M2CHA_GPIO		( 11	)
#define HARDWARE_M2CHB_GPIO		( 10	)
#define HARDWARE_M3CHA_GPIO		( 7	)
#define HARDWARE_M3CHB_GPIO		( 6	)
#define HARDWARE_M4CHA_GPIO		( 2	)
#define HARDWARE_M4CHB_GPIO		( 3	)


/**
 * Pinos utilizados nas leituras da da alimentação
 * da placa 
 */
#define HARDWARE_VIN_GPIO		( 26	)
#define HARDWARE_VCC_GPIO		( 27	)
#define HARDWARE_V1_GPIO		( 28	)


#endif /* hardware_H_ */
