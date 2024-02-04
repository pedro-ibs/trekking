/**
 * vl53l0x.c
 *
 *  @date Created at:	17/06/2022 10:57:08
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
#include "vl53l0x.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include <zephyr.h>
#include <device.h>
#include <errno.h>

#include <sys/util.h>
#include <sys/printk.h>

#include <drivers/i2c.h>
#include <drivers/sensor.h>


#include <hardware.h>
/* Setings -----------------------------------------------------------------------------------------------------------------------------------------------*/
/* Function prototype ------------------------------------------------------------------------------------------------------------------------------------*/
/* Setup -------------------------------------------------------------------------------------------------------------------------------------------------*/
/* -------------------------------------------------------------------------------------------------------------------------------------------------------*/


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


/*########################################################################################################################################################*/
/*########################################################################################################################################################*/
/*########################################################################################################################################################*/
/*-------------------------------------------------------------------- Local Functions -------------------------------------------------------------------*/
/*########################################################################################################################################################*/
