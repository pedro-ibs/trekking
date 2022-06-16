/**
 * motor.h
 *
 *  @date Created at:	14/06/2022 15:39:55
 *	@author:	Pedro Igor B. S.
 *	@email:		pedro.igor.ifsp@gmail.com
 * 	GitHub:		https://github.com/pedro-ibs
 * 	tabSize:	8
 *
 * #######################################################################
 *
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
 * Cada par de motor utiliza uma PONTE H, sendo controlado por 4 pinos de
 * saída:
 * 
 * 			      ___________
 * 			     |		|
 * 			M1 --| PONTE 1	|-- M2
 * 			     |		|
 *			M3 --| PONTE 2	|-- M4
 *			     |__________|	
 */

/* Includes ---------------------------------------------------------------------------------------------------------------------------------------------*/
#include <zephyr.h>



#ifndef motor_H_
#define motor_H_

/* settings ----------------------------------------------------------------------------------------------------------------------------------------------*/

typedef enum {
	M1A = 0,
	M1B,
	M2A,
	M2B,
	M3A,
	M3B,
	M4A,
	M4B,
	QTY_MOTORS
} motors_gpio ;

/* Definition --------------------------------------------------------------------------------------------------------------------------------------------*/


uint8_t motor_uSetup(void);

void motor_vToFront( motors_gpio mxa, motors_gpio mxb );
void motor_vToBack( motors_gpio mxa, motors_gpio mxb );
void motor_vToStop( motors_gpio mxa, motors_gpio mxb );
void motor_vTurnoff( motors_gpio mxa, motors_gpio mxb );

#endif /* motor_H_ */
