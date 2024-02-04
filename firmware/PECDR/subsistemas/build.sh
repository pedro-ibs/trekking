#! /bin/bash

PICO_SDK_PATH="~/pico/pico-sdk"
PICO_EXAMPLES_PATH="~/pico/pico-examples"
PICO_PLATFORM="rp2040"

## select board
PICO_BOARD="pico_w"
#PICO_BOARD="pico"

## enable comunnicarion by uart 
## 1 to enable 0 to desable
UART_ENABLE="1"
USB_CDC_ENABLE="0"


## environment variable 
export PICO_SDK_PATH=$PICO_SDK_PATH
export PICO_EXAMPLES_PATH=$PICO_EXAMPLES_PATH
export PICO_PLATFORM=$PICO_PLATFORM
export PICO_BOARD=$PICO_BOARD


## configures the libraries that will be used in the project like:
## hardware_pwm
## hardware_uart
LIBRARIES="

	pico_cyw43_arch_none
	# pico_cyw43_arch_lwip_poll
	# pico_cyw43_arch_lwip_threadsafe_background

	pico_stdlib
	pico_multicore

	hardware_pwm
	hardware_uart
	hardware_adc
	hardware_dma
	hardware_timer

"

## read folders subfolders and files
FIND_INC_H=$(find includes | grep "\.h")

FIND_LIB_H=$(find lib | grep "\.h")
FIND_LIB_C=$(find lib | grep "\.c")
FIND_SRC_C=$(find src | grep "\.c")

FIND_INCLUDES_D=$(find includes -type d)
FIND_LIB_D=$(find lib -type d)
FIND_SRC_D=$(find src -type d)


## build CMakeLists.txt file
echo "## INIT ##


## DO NOT CHANGE THIS FILE IT IS GENERATED
## AUTOMATICALLY BY builds.sh

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set( PICO_SDK_PATH  $PICO_SDK_PATH )
set( PICO_EXAMPLES_PATH  $PICO_EXAMPLES_PATH )
set( PICO_PLATFORM  $PICO_PLATFORM )
set( PICO_BOARD  $PICO_BOARD )

## Initialise pico_sdk from installed location
## (note this can come from environment, CMake cache etc)
set(PICO_SDK_PATH \"$PICO_SDK_PATH\")

## Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(RPI_PICO_SDK C CXX ASM)

## Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

## Add executables. Default name is the project name, version 0.1

## Project directories
include_directories( 
$FIND_INCLUDES_D
$FIND_LIB_D
$FIND_SRC_D
)

## Project Files
add_executable( RPI_PICO_SDK
$FIND_SRC_C
$FIND_INC_H
$FIND_LIB_H
$FIND_LIB_C
)

pico_set_program_name(RPI_PICO_SDK \"RPI_PICO_SDK\")
pico_set_program_version(RPI_PICO_SDK "0.1")

pico_enable_stdio_uart(RPI_PICO_SDK $UART_ENABLE)
pico_enable_stdio_usb(RPI_PICO_SDK $USB_CDC_ENABLE)

## Add the standard library to the build
target_link_libraries(RPI_PICO_SDK pico_stdlib)


## Add any user requested libraries
target_link_libraries(RPI_PICO_SDK
$LIBRARIES
)

pico_add_extra_outputs(RPI_PICO_SDK)

## END ##" > CMakeLists.txt

# rm -r build

mkdir build
cd build
cmake ..

make -j4

echo " "
# echo " "
# echo "< ################################################################ >"
# echo "SRAM	= data + bss"
# echo "FLASH	= text + data"

arm-none-eabi-size RPI_PICO_SDK.elf

echo " "
echo " "
