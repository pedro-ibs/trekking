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

#include <sys/util.h>
#include <sys/printk.h>

#include <drivers/gpio.h>

/* Setings -----------------------------------------------------------------------------------------------------------------------------------------------*/
#define LED0_NODE			DT_ALIAS(led0)
/* Function prototype ------------------------------------------------------------------------------------------------------------------------------------*/
void blink( void );
void timer_handler(struct k_timer *timer_id);
/* Setup -------------------------------------------------------------------------------------------------------------------------------------------------*/
static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED0_NODE, gpios);
K_TIMER_DEFINE(app_timer, timer_handler, NULL);
/* -------------------------------------------------------------------------------------------------------------------------------------------------------*/

void timer_handler(struct k_timer *timer_id) {
	gpio_pin_toggle_dt(&led);
}

void main(void) {	
	if (!device_is_ready(led.port)) return;
	gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE);

	k_timer_start(&app_timer, K_NO_WAIT, K_MSEC(500));
	printk("started \r\n");
}

/*########################################################################################################################################################*/
/*########################################################################################################################################################*/
/*########################################################################################################################################################*/
/*-------------------------------------------------------------------- Local Functions -------------------------------------------------------------------*/
/*########################################################################################################################################################*/

void blink( void ) {
	gpio_pin_toggle_dt(&led);
}
