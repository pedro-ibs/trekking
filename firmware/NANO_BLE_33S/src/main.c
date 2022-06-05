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
/* Setings -----------------------------------------------------------------------------------------------------------------------------------------------*/
#define LED0_NODE			DT_ALIAS(led3)
#define I2C_NODE			DT_NODELABEL(i2c1)
#define UART_NODE 			DT_NODELABEL(uart0)

#define APP_WORK_QUEUE_STACK_SIZE	4096
#define APP_WORK_PRIORITY		5
/* Function prototype ------------------------------------------------------------------------------------------------------------------------------------*/
void blink( void );
void usb_setup(void);
void vl53l0x(void);

void timer_handler(struct k_timer *timer_id);

/* Setup -------------------------------------------------------------------------------------------------------------------------------------------------*/
static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED0_NODE, gpios);

BUILD_ASSERT(DT_NODE_HAS_COMPAT(DT_CHOSEN(zephyr_console), zephyr_cdc_acm_uart), "Console device is not ACM CDC UART device");
K_TIMER_DEFINE(app_timer, timer_handler, NULL);
/* -------------------------------------------------------------------------------------------------------------------------------------------------------*/

void timer_handler(struct k_timer *timer_id) {
	gpio_pin_toggle_dt(&led);
}


void main(void) {	
	if (!device_is_ready(led.port)) return;
	gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE);

	usb_setup();
	k_timer_start(&app_timer, K_NO_WAIT, K_SECONDS(1));

	printk("started \r\n");

	vl53l0x();
}

/*########################################################################################################################################################*/
/*########################################################################################################################################################*/
/*########################################################################################################################################################*/
/*-------------------------------------------------------------------- Local Functions -------------------------------------------------------------------*/
/*########################################################################################################################################################*/

void usb_setup(void){
	const struct device *dev = DEVICE_DT_GET(DT_CHOSEN(zephyr_console));
	uint32_t dtr = 0;

	if (usb_enable(NULL)) {
		return;
	}

	/* Poll if the DTR flag was set */
	while (!dtr) {
		uart_line_ctrl_get(dev, UART_LINE_CTRL_DTR, &dtr);
		/* Give CPU resources to low priority threads. */
		k_sleep(K_MSEC(100));
	}
}

void blink( void ) {
	gpio_pin_toggle_dt(&led);
}

void vl53l0x(void){
	const struct device *dev = device_get_binding(DT_LABEL(DT_INST(0, st_vl53l0x)));
	struct sensor_value value;
	int ret;

	if (dev == NULL) {
		printk("Could not get VL53L0X device\n");
		return;
	}

	while (1) {
		ret = sensor_sample_fetch(dev);
		if (ret) {
			printk("sensor_sample_fetch failed ret %d\n", ret);
			return;
		}

		ret = sensor_channel_get(dev, SENSOR_CHAN_PROX, &value);
		printk("prox is %d\n", value.val1);

		ret = sensor_channel_get(dev,
					 SENSOR_CHAN_DISTANCE,
					 &value);
		printk("distance is %f m\n", sensor_value_to_double(&value));

		k_sleep(K_MSEC(1000));
	}
}