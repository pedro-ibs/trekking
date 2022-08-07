
# SPDX-License-Identifier: Apache-2.0

# NÃO MUDE ESTE ARQUIVO ELE É GERADO
# AUTOMATICAMENTE

cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

project(RPI_PICO)

include_directories( 
includes
lib
lib/motor
lib/led
lib/comm
lib/gprs
lib/textProtocol
src
)

target_sources(app PRIVATE
src/main.c
includes/config.h
includes/hardware.h
lib/motor/motor.h
lib/led/led.h
lib/comm/comm.h
lib/gprs/gprs.h
lib/textProtocol/textProtocol.h
lib/motor/motor.c
lib/led/led.c
lib/comm/comm.c
lib/gprs/gprs.c
lib/textProtocol/textProtocol.c
) 
