
# SPDX-License-Identifier: Apache-2.0

# NÃO MUDE ESTE ARQUIVO ELE É GERADO
# AUTOMATICAMENTE

cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS {ZEPHYR_BASE})

project(NANO_BLE_33S)

include_directories( 
includes
lib
lib/usb
lib/vl53l0x
lib/led
src
)

target_sources(app PRIVATE
src/main.c
includes/hardware.h
lib/usb/usb_cdc_acm_uart.h
lib/vl53l0x/vl53l0x.h
lib/led/led.h
lib/usb/usb_cdc_acm_uart.c
lib/vl53l0x/vl53l0x.c
lib/led/led.c
) 
