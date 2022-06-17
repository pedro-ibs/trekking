/**
 * comm.c
 *
 *  @date Created at:	16/06/2022 17:13:50
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
#include "comm.h"

#include <zephyr.h>
#include <device.h>
#include <drivers/uart.h>
#include <string.h>

#include <hardware.h>
#include <config.h>

#include <led.h>


/* Setings -----------------------------------------------------------------------------------------------------------------------------------------------*/
/* Function prototype ------------------------------------------------------------------------------------------------------------------------------------*/
void comm_vMessageSubmit(uart_device dev);
void comm_vCleanMessage(uart_device dev);
void uart_vBuildMessage(uart_device dev, char data);
void uart0_cb(const struct device *dev, void *user_data);
void uart0_timeout_handler(struct k_timer *timer_id);
void uart1_timeout_handler(struct k_timer *timer_id);
/* Setup -------------------------------------------------------------------------------------------------------------------------------------------------*/
K_MSGQ_DEFINE(uart0_msgq, UART_MESSAGE_SIZE, UART_QUEUE_SIZE, 4);
K_MSGQ_DEFINE(uart1_msgq, UART_MESSAGE_SIZE, UART_QUEUE_SIZE, 4);

typedef struct comm {
	char message[UART_MESSAGE_SIZE];
	size_t position;

	struct k_msgq *msgq;
	const struct device *dev;
} uart_data;


static uart_data uart_d[UART_QTY] = {
	{"", 0, &uart0_msgq, DEVICE_DT_GET( UART_RASP_RPI_NODE )},
	{"", 0, &uart1_msgq, DEVICE_DT_GET( UART_RASP_RPI_NODE )}
};

/* -------------------------------------------------------------------------------------------------------------------------------------------------------*/


void comm_vSetup(void){

	comm_vCleanMessage(UART0);
	comm_vCleanMessage(UART1);

	uart_irq_callback_user_data_set(uart_d[UART0].dev, uart0_cb, NULL);
	uart_irq_rx_enable(uart_d[UART0].dev);
}

void comm_vGetMessage(uart_device dev, char *msg, k_timeout_t timeout){
	k_msgq_get(uart_d[dev].msgq, msg, K_FOREVER);
}

void comm_uSendChar( uart_device dev, char c ){
	uart_poll_out(uart_d[dev].dev, c);
}

void comm_uSendString( uart_device dev, const char *str ){
	size_t uSize = strlen(str);
	for (size_t i = 0; i < uSize; i++) {
		comm_uSendChar(dev, str[i]);
	}
}

void comm_uSendStringLn( uart_device dev, const char *str ){
	comm_uSendString( dev, str );
	comm_uSendString( dev, "\r\n" );
}


/*########################################################################################################################################################*/
/*########################################################################################################################################################*/
/*########################################################################################################################################################*/
/*-------------------------------------------------------------------- Local Functions -------------------------------------------------------------------*/
/*########################################################################################################################################################*/


void comm_vMessageSubmit(uart_device dev){
	if ( k_msgq_put(uart_d[dev].msgq, uart_d[dev].message, K_NO_WAIT) != 0){
		k_msgq_cleanup(uart_d[dev].msgq);
	}
}

void comm_vCleanMessage(uart_device dev){
	uart_d[dev].position = 0;

	for (size_t i = 0; i < UART_MESSAGE_SIZE; i++){
		uart_d[dev].message[i] = 0x00;
	}
}

void uart_vBuildMessage(uart_device dev, char data){
	
	uart_d[dev].message[uart_d[dev].position++] = data;

	if( ( uart_d[dev].position >= UART_MESSAGE_SIZE ) || ( data == '\n' ) || ( data == '\r' ) ){

		led_vPing();

		comm_vMessageSubmit(dev);

		comm_vCleanMessage(dev);
		return;
	}
}


void uart0_cb(const struct device *dev, void *user_data) {
	uint8_t c;

	if (!uart_irq_update(dev)) {
		return;
	}

	while (uart_irq_rx_ready(dev)) {
		uart_fifo_read(dev, &c, 1);
		uart_vBuildMessage(UART0, c);
	}

}
