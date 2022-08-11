/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <config.h>
#include <simple_uart.h>
#include <textProtocol.h>
#include <motor.h> 

int main() {

	uart_vSetup();

	uart_vSendStringLn("started!");

	motor_vSetGpio(HARDWARE_M1CHA_GPIO, HARDWARE_M1CHB_GPIO);


	while (true) {

		if(uart_uGetBufferSize() > 0) {
			if ( textp_bFindString( uart_pcGetBuffer(), "}" ) ){
				uart_vSendString(uart_pcGetBuffer());
				uart_vCleanBuffer();
			}
		}

		sleep_ms(100);
	}
}
