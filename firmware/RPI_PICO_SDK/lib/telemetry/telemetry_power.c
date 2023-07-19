/**
 * telemetry_power.c
 *
 *  @date Created at:	04/12/2022 11:38:37
 *	@author:	Pedro Igor B. S.
 *	@email:		pibscontato@gmail.com
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
 * Realizar as medidas referente a alimentação da placa
 *
 */



/* Includes ----------------------------------------------------------------------------------------------------------------------------------------------*/
#include "telemetry_power.h"
#include "hardware/adc.h"
#include "hardware/gpio.h"

/* Setings -----------------------------------------------------------------------------------------------------------------------------------------------*/
/* Function prototype ------------------------------------------------------------------------------------------------------------------------------------*/
#define TO_VOLTAGE( BIT )     ( ( (float)BIT / 4096.0 ) * 36.3 )
/* Setup -------------------------------------------------------------------------------------------------------------------------------------------------*/
/* -------------------------------------------------------------------------------------------------------------------------------------------------------*/


void telemetry_vSetup(void){
	adc_init();
	
	/**
	 *  POWER INPUT > -----| 0R15 |----- < REST OF CIRCUIT
	 *                  ^            ^
	 *                  A            B
	 * 
	 * A -> HARDWARE_POWER_SUPPLY_1_GPIO
	 * B ->HARDWARE_POWER_SUPPLY_1_GPIO
	 */
	adc_gpio_init( HARDWARE_POWER_SUPPLY_1_GPIO     );      // ADC 2
	adc_gpio_init( HARDWARE_POWER_SUPPLY_2_GPIO     );      // ADC 1
	adc_gpio_init( HARDWARE_POWER_SYSTEM_GPIO       );      // ADC 0


}

float telemetry_fGetPowerSystem( void ){
	adc_select_input( 0 );
	return TO_VOLTAGE( adc_read() );
}

float telemetry_fGetPowerSupplyA( void ){
	adc_select_input( 2 );
	return TO_VOLTAGE( adc_read() );
}

float telemetry_fGetPowerSupplyB( void ){
	adc_select_input( 1 );
	return TO_VOLTAGE( adc_read() );
}





/*########################################################################################################################################################*/
/*########################################################################################################################################################*/
/*########################################################################################################################################################*/
/*-------------------------------------------------------------------- Local Functions -------------------------------------------------------------------*/
/*########################################################################################################################################################*/
