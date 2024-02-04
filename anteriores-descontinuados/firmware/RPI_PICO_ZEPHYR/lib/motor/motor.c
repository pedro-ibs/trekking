/**
 * motor.c
 *
 *  @date Created at:	14/06/2022 15:40:32
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




/* Includes ----------------------------------------------------------------------------------------------------------------------------------------------*/
#include "motor.h"

#include <zephyr.h>
#include <device.h>
#include <devicetree.h>

#include <drivers/gpio.h>

#include <hardware.h>

/* Setings -----------------------------------------------------------------------------------------------------------------------------------------------*/
/* Function prototype ------------------------------------------------------------------------------------------------------------------------------------*/
/* Setup -------------------------------------------------------------------------------------------------------------------------------------------------*/

static const struct gpio_dt_spec scxMotors[QTY_MOTORS] = {
	GPIO_DT_SPEC_GET(M1A_NODE, gpios),
	GPIO_DT_SPEC_GET(M1B_NODE, gpios),
	GPIO_DT_SPEC_GET(M2A_NODE, gpios),
	GPIO_DT_SPEC_GET(M2B_NODE, gpios),
	GPIO_DT_SPEC_GET(M3A_NODE, gpios),
	GPIO_DT_SPEC_GET(M3B_NODE, gpios),
	GPIO_DT_SPEC_GET(M4A_NODE, gpios),
	GPIO_DT_SPEC_GET(M4B_NODE, gpios)
};

/* -------------------------------------------------------------------------------------------------------------------------------------------------------*/

uint8_t motor_uSetup(void){

	for(uint8_t i = M1A; i<QTY_MOTORS; i++ ){
		if (!device_is_ready(scxMotors[i].port)) return 1;
		
		gpio_pin_configure_dt(&scxMotors[i], GPIO_OUTPUT_LOW);
		gpio_pin_set_dt(&scxMotors[i], false);
	}

	return 0;
}



void motor_vToFront( motors_gpio mxa, motors_gpio mxb  ){
	gpio_pin_set_dt(&scxMotors[mxa], true);
	gpio_pin_set_dt(&scxMotors[mxb], false);
}

void motor_vToBack( motors_gpio mxa, motors_gpio mxb ){
	gpio_pin_set_dt(&scxMotors[mxa], false);
	gpio_pin_set_dt(&scxMotors[mxb], true);
}

void motor_vToStop( motors_gpio mxa, motors_gpio mxb ){
	gpio_pin_set_dt(&scxMotors[mxa], true);
	gpio_pin_set_dt(&scxMotors[mxb], true);
}

void motor_vTurnoff( motors_gpio mxa, motors_gpio mxb ){
	gpio_pin_set_dt(&scxMotors[mxa], false);
	gpio_pin_set_dt(&scxMotors[mxb], false);
}

/*########################################################################################################################################################*/
/*########################################################################################################################################################*/
/*########################################################################################################################################################*/
/*-------------------------------------------------------------------- Local Functions -------------------------------------------------------------------*/
/*########################################################################################################################################################*/
