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
void motor_vConfig(uint gpio, uint32_t wrap, uint32_t divisor16, uint16_t duty_cycle);
/* Setup -------------------------------------------------------------------------------------------------------------------------------------------------*/
/* -------------------------------------------------------------------------------------------------------------------------------------------------------*/

void motor_vSetup( motor *m, uint32_t frequency, uint16_t duty_cycle) {
	m->pwm = 0;

	uint32_t divisor16 = CONFIG_PWM_SYS_FREQUENCY_HZ / frequency / 4096 + ( CONFIG_PWM_SYS_FREQUENCY_HZ % ( frequency * 4096 ) != 0 );
	
	if( divisor16 / 16 == 0 ) {
		divisor16 = 16;
	}

	m->pwm_max = CONFIG_PWM_SYS_FREQUENCY_HZ * 16 / divisor16 / frequency - 1;


	motor_vConfig(m->ma, m->pwm_max, divisor16, duty_cycle);
	motor_vConfig(m->mb, m->pwm_max, divisor16, duty_cycle);
}


void motor_vToFront( motor *m, uint32_t duty_cycle ) {
	m->pwm = duty_cycle;

	if(m->pwm > m->pwm_max) m->pwm = m->pwm_max-1;

	pwm_set_gpio_level(m->ma, m->pwm );
	pwm_set_gpio_level(m->mb, 0 );
}

void motor_vToBack( motor *m, uint32_t duty_cycle ) {
	m->pwm = duty_cycle;

	if(m->pwm > m->pwm_max) m->pwm = m->pwm_max-1;
	
	pwm_set_gpio_level(m->ma, 0 );
	pwm_set_gpio_level(m->mb, m->pwm );
}


void motor_vToBraking( motor *m, uint32_t duty_cycle ) {
	m->pwm = duty_cycle;

	if(m->pwm > m->pwm_max) m->pwm = m->pwm_max-1;

	pwm_set_gpio_level(m->ma, m->pwm );
	pwm_set_gpio_level(m->mb, m->pwm );
}

void motor_vTurnOff( motor *m ) {
	motor_vToBraking(m, 0);
}

/**
 * @brief detecta a direção do movimento de acordo com o sinal 
 * configure a macro CONFIG_DETECT_TO_FRONT e CONFIG_DETECT_TO_BACK
 * para definir o padrão do sentido.
 */
void motor_vMove( motor *m,  int duty_cycle ){
	if ( duty_cycle	CONFIG_DETECT_TO_FRONT ){
		motor_vToFront(m, abs(duty_cycle) );
		return;
	}
	
	if ( duty_cycle	CONFIG_DETECT_TO_BACK ){
		motor_vToBack(m, abs(duty_cycle) );
		return;
	}
	
	motor_vTurnOff(m); 
}



/*########################################################################################################################################################*/
/*########################################################################################################################################################*/
/*########################################################################################################################################################*/
/*-------------------------------------------------------------------- Local Functions -------------------------------------------------------------------*/
/*########################################################################################################################################################*/

void motor_vConfig(uint gpio, uint32_t wrap, uint32_t divisor16, uint16_t duty_cycle) {

	gpio_init( gpio );
	gpio_set_function( gpio, GPIO_FUNC_PWM );

	uint slice_num	= pwm_gpio_to_slice_num	( gpio );
	uint channel	= pwm_gpio_to_channel	( gpio );


	pwm_set_clkdiv_int_frac	( slice_num, divisor16 / 16, divisor16 & 0xF	);
	pwm_set_wrap		( slice_num, wrap				);
	pwm_set_chan_level	( slice_num, channel, wrap * duty_cycle / 100	);
	pwm_set_enabled		( slice_num, true				); 

}