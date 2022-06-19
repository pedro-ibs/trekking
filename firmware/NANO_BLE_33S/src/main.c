/**
 * mam.c
 *
 *  @date Created at:	09/05/2022 11:50:04
 *	@author:	Pedro Igor B. S.
 *	@email:		pedro.igor.ifsp@gmail.com
 * 	GitHub:		https://github.com/pedro-ibs
 * 	tabSize:	8
 *
 * #######################################################################
 *
 * TODO: Licence
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
 * PISCA TIMER
 *
 */

/* Includes ----------------------------------------------------------------------------------------------------------------------------------------------*/
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include <zephyr.h>
#include <device.h>
#include <errno.h>

#include <sys/util.h>
#include <sys/printk.h>

#include <drivers/uart.h>
#include <drivers/gpio.h>
#include <drivers/i2c.h>
#include <drivers/sensor.h>

#include <usb/usb_device.h>


#include <hardware.h>
#include <usb_cdc_acm_uart.h>
#include <led.h>
#include <vl53l0x.h>


/* Setings -----------------------------------------------------------------------------------------------------------------------------------------------*/

/* Function prototype ------------------------------------------------------------------------------------------------------------------------------------*/
void vl53l0x(void);
/* Setup -------------------------------------------------------------------------------------------------------------------------------------------------*/
/* -------------------------------------------------------------------------------------------------------------------------------------------------------*/

void main(void) {	
	led_vSetup();

	usb_vSetup();

	led_vPeriodicPingStart(K_SECONDS(1));

	printk("started \r\n");

	vl53l0x();
}

/*########################################################################################################################################################*/
/*########################################################################################################################################################*/
/*########################################################################################################################################################*/
/*-------------------------------------------------------------------- Local Functions -------------------------------------------------------------------*/
/*########################################################################################################################################################*/

