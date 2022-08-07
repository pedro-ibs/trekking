/**
 * hardware.h
 *
 *  @date Created at:	16/06/2022 12:57:19
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
#include <zephyr.h>
#include <device.h>
#include <devicetree.h>

#include <drivers/gpio.h>


#ifndef hardware_H_
#define hardware_H_

/* settings ----------------------------------------------------------------------------------------------------------------------------------------------*/
/* Definition --------------------------------------------------------------------------------------------------------------------------------------------*/

/**
 * Pinos de controle  dos motores
 */
#define M1A_NODE		DT_ALIAS( m1a			)
#define M1B_NODE		DT_ALIAS( m1b			)

#define M2A_NODE		DT_ALIAS( m2a			)
#define M2B_NODE		DT_ALIAS( m2b			)

#define M3A_NODE		DT_ALIAS( m3a			)
#define M3B_NODE		DT_ALIAS( m3b 			)

#define M4A_NODE		DT_ALIAS( m4a 			)
#define M4B_NODE		DT_ALIAS( m4b 			)


/**
 *  GPRS
 */
#define GPRS_RST_NODE		DT_ALIAS( gprs_rst 		)

/**
 * Led -IHM
 */
#define LED0_NODE		DT_ALIAS( led0			)

/**
 * Comunicação serial raspberry - rpi_pico
 */
#define UART0_RASP_RPI_NODE 	DT_ALIAS( uart0 		)
#define UART1_RASP_RPI_NODE 	DT_ALIAS( uart1 		)


#endif /* hardware_H_ */
