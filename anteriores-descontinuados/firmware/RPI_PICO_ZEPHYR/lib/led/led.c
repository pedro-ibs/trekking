/**
 * led.c
 *
 *  @date Created at:	16/06/2022 13:18:30
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
 *
 * TODO: documentation or resume or Abstract
 *
 */



/* Includes ----------------------------------------------------------------------------------------------------------------------------------------------*/
#include "led.h"

#include <zephyr.h>
#include <device.h>
#include <devicetree.h>
#include <sys/util.h>
#include <sys/printk.h>

#include <drivers/gpio.h>

#include <hardware.h>

/* Setings -----------------------------------------------------------------------------------------------------------------------------------------------*/
/* Function prototype ------------------------------------------------------------------------------------------------------------------------------------*/
void led_timer_handler(struct k_timer *timer_id);
void ping_work_handler( struct k_work *work );
/* Setup -------------------------------------------------------------------------------------------------------------------------------------------------*/
static const struct gpio_dt_spec led		= GPIO_DT_SPEC_GET(LED0_NODE,		gpios);
K_TIMER_DEFINE(led_timer, led_timer_handler, NULL);
K_WORK_DEFINE(ping_work, ping_work_handler);
/* -------------------------------------------------------------------------------------------------------------------------------------------------------*/

void led_vSetup(void){
	if (!device_is_ready(led.port))	 return;
	gpio_pin_configure_dt(&led, GPIO_OUTPUT_HIGH);
}

void led_vPeriodicPingStart(k_timeout_t timeout){
	k_timer_start(&led_timer, K_NO_WAIT, timeout);
}


void led_vPeriodicPingStop(void){
	k_timer_stop(&led_timer);
}

void led_vPing(void){
	k_work_submit(&ping_work);
}


/*########################################################################################################################################################*/
/*########################################################################################################################################################*/
/*########################################################################################################################################################*/
/*-------------------------------------------------------------------- Local Functions -------------------------------------------------------------------*/
/*########################################################################################################################################################*/

void led_timer_handler(struct k_timer *timer_id) {
	led_vPing();

}

void ping_work_handler( struct k_work *work ){
	gpio_pin_set_dt(&led, true);
	k_sleep(K_MSEC(20));
	gpio_pin_set_dt(&led, false);
}
