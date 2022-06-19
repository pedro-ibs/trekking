/**
 * mam.c
 *
 *  @date Created at:	09/05/2022 11:50:04
 *	@author:	Pedro Igor B. S.
 *	@email:		pedro.igor.ifsp@gmail.com
 * 	GitHub:		https://github.com/pedro-ibs
 * 	tabSize:	8
 *
 * ####################################################################### *
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
#include <devicetree.h>
#include <sys/util.h>
#include <sys/printk.h>

#include <drivers/gpio.h>
#include <drivers/uart.h>

#include <config.h>

#include <motor.h>
#include <gprs.h>
#include <led.h>
#include <comm.h>
#include <textProtocol.h>

/* Setings -----------------------------------------------------------------------------------------------------------------------------------------------*/
/* Function prototype ------------------------------------------------------------------------------------------------------------------------------------*/
/* Setup -------------------------------------------------------------------------------------------------------------------------------------------------*/
/* -------------------------------------------------------------------------------------------------------------------------------------------------------*/


void main(void) {	
	
	motor_uSetup();
	gprs_vSetup();
	led_vSetup();
	comm_vSetup();

	motor_vTurnoff(M1A, M1B);
	motor_vTurnoff(M2A, M2B);
	motor_vTurnoff(M3A, M3B);
	motor_vTurnoff(M4A, M4B);

	printk("started \r\n");

	// led_vPeriodicPingStart(K_MSEC(1000));

	char bff[UART_MESSAGE_SIZE] = "";

	while (true) {
		comm_vGetMessage(UART0, bff, K_FOREVER);

		comm_uSendStringLn(UART0, bff);

		if (textp_bFindString(bff,"toFront") ) { 

			motor_vToFront(M1A, M1B);
			motor_vToFront(M2A, M2B);
			motor_vToFront(M3A, M3B);
			motor_vToFront(M4A, M4B);
		
		} else if (textp_bFindString(bff,"toBack") ) {
		
			motor_vToBack(M1A, M1B);
			motor_vToBack(M2A, M2B);

			motor_vToBack(M3A, M3B);
			motor_vToBack(M4A, M4B);
		
		} else if (textp_bFindString(bff,"turnLeft") ) {
		
			motor_vToBack(M1A, M1B);
			motor_vToBack(M3A, M3B);

			motor_vToFront(M2A, M2B);
			motor_vToFront(M4A, M4B);
		
		} else if (textp_bFindString(bff,"turnRight") ) {
		
			motor_vToFront(M1A, M1B);
			motor_vToFront(M3A, M3B);
			motor_vToBack(M2A, M2B);
			motor_vToBack(M4A, M4B);
		
		} else /*if (textp_bFindString(bff,"turnoff") )*/ {


			motor_vTurnoff(M1A, M1B);
			motor_vTurnoff(M2A, M2B);
			motor_vTurnoff(M3A, M3B);
			motor_vTurnoff(M4A, M4B);

		}
	}
}

/*########################################################################################################################################################*/
/*########################################################################################################################################################*/
/*########################################################################################################################################################*/
/*-------------------------------------------------------------------- Local Functions -------------------------------------------------------------------*/
/*########################################################################################################################################################*/

