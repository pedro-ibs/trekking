## INIT ##


## DO NOT CHANGE THIS FILE IT IS GENERATED
## AUTOMATICALLY BY builds.sh

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set( PICO_SDK_PATH  /mnt/68063d96-b411-4f54-807a-ab209658d71e/.prog/pico/pico-sdk )
set( PICO_EXAMPLES_PATH  /mnt/68063d96-b411-4f54-807a-ab209658d71e/.prog/pico/pico-examples )
set( PICO_PLATFORM  rp2040 )
set( PICO_BOARD  pico )

## Initialise pico_sdk from installed location
## (note this can come from environment, CMake cache etc)
set(PICO_SDK_PATH "/mnt/68063d96-b411-4f54-807a-ab209658d71e/.prog/pico/pico-sdk")

## Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(RPI_PICO_SDK C CXX ASM)

## Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

## Add executables. Default name is the project name, version 0.1

## Project directories
include_directories( 
includes
lib
lib/textProtocol
lib/simple_uart
lib/servo
lib/motor
lib/pid
src
)

## Project Files
add_executable( RPI_PICO_SDK
src/main.c
includes/hardware.h
includes/lwipopts.h
includes/config.h
lib/textProtocol/textProtocol.h
lib/simple_uart/simple_uart.h
lib/simple_uart/rs485.h
lib/servo/servo.h
lib/motor/motor.h
lib/pid/pid.h
lib/textProtocol/textProtocol.c
lib/simple_uart/simple_uart.c
lib/simple_uart/rs485.c
lib/servo/servo.c
lib/motor/motor.c
lib/pid/pid.c
)

pico_set_program_name(RPI_PICO_SDK "RPI_PICO_SDK")
pico_set_program_version(RPI_PICO_SDK 0.1)

pico_enable_stdio_uart(RPI_PICO_SDK 1)
pico_enable_stdio_usb(RPI_PICO_SDK 0)

## Add the standard library to the build
target_link_libraries(RPI_PICO_SDK pico_stdlib)


## Add any user requested libraries
target_link_libraries(RPI_PICO_SDK


	# pico_cyw43_arch_none
	# pico_cyw43_arch_lwip_poll
	# pico_cyw43_arch_lwip_threadsafe_background

	pico_stdlib
	pico_multicore

	hardware_pwm
	hardware_uart
	hardware_adc
	hardware_dma
	hardware_timer


)

pico_add_extra_outputs(RPI_PICO_SDK)

## END ##
