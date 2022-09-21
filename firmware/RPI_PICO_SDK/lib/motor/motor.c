/**
 * motor.c
 *
 *  @date Created at:	10/08/2022 19:53:57
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
#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/time.h"
#include "hardware/irq.h"
#include "hardware/pwm.h"


/* Setings -----------------------------------------------------------------------------------------------------------------------------------------------*/
/* Function prototype ------------------------------------------------------------------------------------------------------------------------------------*/
/* Setup -------------------------------------------------------------------------------------------------------------------------------------------------*/
/* -------------------------------------------------------------------------------------------------------------------------------------------------------*/

void motor_vSetGpio( uint8_t ma, uint8_t mb ){

	gpio_init(ma);
	gpio_init(mb);
	gpio_set_function(ma, GPIO_FUNC_PWM);
	gpio_set_function(mb, GPIO_FUNC_PWM);

	uint slice_num = pwm_gpio_to_slice_num(ma);

	pwm_set_wrap(slice_num, 3);
	pwm_set_chan_level(slice_num, PWM_CHAN_A, 3);
	pwm_set_chan_level(slice_num, PWM_CHAN_B, 3);
	pwm_set_enabled(slice_num, true);

}




/*########################################################################################################################################################*/
/*########################################################################################################################################################*/
/*########################################################################################################################################################*/
/*-------------------------------------------------------------------- Local Functions -------------------------------------------------------------------*/
/*########################################################################################################################################################*/




