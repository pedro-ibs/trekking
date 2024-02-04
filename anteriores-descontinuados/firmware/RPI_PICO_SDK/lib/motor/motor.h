/**
 * motor.h
 *
 *  @date Created at:	10/08/2022 19:53:30
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
#include <config.h>

typedef struct {

	uint8_t ma;
	uint8_t mb;

	uint32_t pwm;

	uint32_t pwm_max;

} motor;




#ifndef motor_H_
#define motor_H_

/* settings ----------------------------------------------------------------------------------------------------------------------------------------------*/
/* Definition --------------------------------------------------------------------------------------------------------------------------------------------*/

void motor_vSetup( motor *m, uint32_t frequency, uint16_t duty_cycle);

void motor_vToFront( motor *m, uint32_t duty_cycle );
void motor_vToBack( motor *m, uint32_t duty_cycle );
void motor_vToBraking( motor *m, uint32_t duty_cycle );
void motor_vTurnOff( motor *m );
void motor_vMove( motor *m,  int duty_cycle );


#endif /* motor_H_ */
