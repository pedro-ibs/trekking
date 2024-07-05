/**
 * motor.h
 *
 *  @date Created at:	02/07/2024, 21:19:46
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
 * Baseado em:
 * 	https://github.com/pedro-ibs/bdesc-s10e-rtr-example-control/tree/main
 * 
 * Controle dos motores utilizando o bdesc-s10e-rtr
 *
 */

/* Includes ---------------------------------------------------------------------------------------------------------------------------------------------*/
#include <config.h>
#include <hardware.h>
#include <servo.h>
#include <pid.h>

#ifndef motor_H_
#define motor_H_

/* macro ------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Definition --------------------------------------------------------------------------------------------------------------------------------------------*/

void motor_vBind( servo *motor );

void motor_vToFront( servo *motor,  float v );
void motor_vPreoareToBack( servo *motor );
void motor_vToBack( servo *motor,  float v );


void motor_vStop( servo *motor );



#endif /* motor_H_ */
