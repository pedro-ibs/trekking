/**
 * servo.c
 *
 *  @date Created at:	01/07/2024, 21:48:07
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
 * Valores encrontrados para os servos
 * pulso [us]	angulos [graus]
 * 400		0º 
 * 2000		180º
 * 
 * usando de referencia os a estrutura do robo.
 *
 */



/* Includes ----------------------------------------------------------------------------------------------------------------------------------------------*/
#include "servo.h"
/* Setings -----------------------------------------------------------------------------------------------------------------------------------------------*/
#define PWM_FREQUENCY		( ( uint32_t ) 400 			)
#define PWM_WARP_BIAS		( ( uint32_t ) 12452			)
#define PWM_WARP		( ( uint32_t ) 65535 - PWM_WARP_BIAS	)
/* Setup -------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Function prototype ------------------------------------------------------------------------------------------------------------------------------------*/
/* -------------------------------------------------------------------------------------------------------------------------------------------------------*/
#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/time.h"
#include "hardware/irq.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"

void servo_vInit( servo *s  ){
	s->value = 0;

	 uint32_t clock = clock_get_hz(clk_sys);

	uint32_t divisor16 = clock / CONFIG_PWM_FREQUENCY_HZ / 4096 + ( clock % ( CONFIG_PWM_FREQUENCY_HZ * 4096 ) != 0 );

	if( divisor16 / 16 == 0 ) {
		divisor16 = 16;
	}

	gpio_init( s->gpio );
	gpio_set_function( s->gpio, GPIO_FUNC_PWM );

	uint slice_num	= pwm_gpio_to_slice_num	( s->gpio );
	uint channel	= pwm_gpio_to_channel	( s->gpio );


	pwm_set_clkdiv_int_frac	( slice_num, divisor16 / 16, divisor16 & 0xF	);
	pwm_set_wrap		( slice_num, PWM_WARP				);
	pwm_set_chan_level	( slice_num, channel, 0				);
	pwm_set_enabled		( slice_num, true				); 

}

void servo_vWritePulse( servo *s, uint16_t pulse_us ){

	s->value =   ( ( pulse_us * PWM_WARP ) / 2000 );
	
	pwm_set_gpio_level(s->gpio, s->value );

}

void servo_vWriteAngle( servo *s, float degree ){

	uint16_t pulse_us = 1000 + ( ( degree * 1000.00 ) / 180.00 );

	servo_vWritePulse( s, pulse_us );
}


/*########################################################################################################################################################*/
/*########################################################################################################################################################*/
/*########################################################################################################################################################*/
/*--------------------------------------------------------------------- Local Functions ------------------------------------------------------------------*/
/*########################################################################################################################################################*/