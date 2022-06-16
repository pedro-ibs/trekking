/**
 * gprs.c
 *
 *  @date Created at:	16/06/2022 11:50:17
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
 *
 * TODO: documentation or resume or Abstract
 *
 */



/* Includes ----------------------------------------------------------------------------------------------------------------------------------------------*/
#include "motor.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include <zephyr.h>
#include <device.h>
#include <devicetree.h>
#include <sys/util.h>
#include <sys/printk.h>

#include <drivers/gpio.h>
#include <drivers/uart.h>

#include <hardware.h>

/* Setings -----------------------------------------------------------------------------------------------------------------------------------------------*/
/* Function prototype ------------------------------------------------------------------------------------------------------------------------------------*/
/* Setup -------------------------------------------------------------------------------------------------------------------------------------------------*/
static const struct gpio_dt_spec gprs_reset	= GPIO_DT_SPEC_GET(GPRS_RST_NODE,	gpios);
/* -------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*########################################################################################################################################################*/
/*########################################################################################################################################################*/
/*########################################################################################################################################################*/
/*-------------------------------------------------------------------- Local Functions -------------------------------------------------------------------*/
/*########################################################################################################################################################*/


void gprs_vSetup(void){
	if (!device_is_ready(gprs_reset.port))	return;
	
	gpio_pin_configure_dt(&gprs_reset, GPIO_OUTPUT_HIGH);

	gpio_pin_set_dt(&gprs_reset, true);
}