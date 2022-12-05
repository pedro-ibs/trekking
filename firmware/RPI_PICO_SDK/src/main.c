/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <config.h>
#include <simple_uart.h>
#include <textProtocol.h>
#include <motor.h> 

static motor motorLeft1  = { HARDWARE_M1CHA_GPIO, HARDWARE_M1CHB_GPIO, 0};
// motor motorLeft2;
// motor motorRight1;
// motor motorRight2;


int main() {

	stdio_init_all();

	uart_vSetup();
	uart_vSendStringLn("00:00;00:00;00:00;00:00;00;00;00");


	motor_vSetup(&motorLeft1, CONFIG_PWM_FREQUENCY_HZ, CONFIG_PWM_DUTY_CYCLE_START);
	// motor_vSetup(&motorLeft2);
	// motor_vSetup(&motorRight1);
	// motor_vSetup(&motorRight2);


	// itoa(num, snum, 10);

	gpio_init(HARDWARE_LED_GPIO);
	gpio_set_dir(HARDWARE_LED_GPIO, GPIO_OUT);


	while (true) {

		gpio_put(HARDWARE_LED_GPIO, 1);
		for (size_t pwm = 0; pwm < motorLeft1.pwm_max; pwm++) {
			motor_vToFront(&motorLeft1, pwm);
			sleep_ms(1);

		}
		
		sleep_ms(1000);

		gpio_put(HARDWARE_LED_GPIO, 0);
		for (size_t pwm = motorLeft1.pwm_max; pwm > 0; pwm--) {
			motor_vToFront(&motorLeft1, pwm);
			sleep_ms(1);

		}
	}
}



