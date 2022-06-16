
# SPDX-License-Identifier: Apache-2.0

# NÃO MUDE ESTE ARQUIVO ELE É GERADO
# AUTOMATICAMENTE

cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS {ZEPHYR_BASE})

project(RPI_PICO)

include_directories( 
includes
lib
lib/motor
lib/led
lib/gprs
src
)

target_sources(app PRIVATE
src/main.c
includes/hardware.h
lib/motor/motor.h
lib/led/led.h
lib/gprs/gprs.h
lib/motor/motor.c
lib/led/led.c
lib/gprs/gprs.c
) 
