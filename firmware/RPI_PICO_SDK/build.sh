#! /bin/bash

# Variaveis do ambiente 
export PICO_SDK_PATH=~/pico/pico-sdk
export PICO_EXAMPLES_PATH=~/pico/pico-examples
# export PICO_EXTRAS_PATH=~/pico/pico-extras
# export PICO_PLAYGROUND_PATH=~/pico/pico-playground
export PICO_PLATFORM=rp2040

# configura as bibliorecas que serão utilizadas no projeto Ex:
# hardware_pwm
# hardware_uart
LIBRARIES="

	pico_multicore
	pico_stdlib

	hardware_pwm
	hardware_uart
	hardware_adc
	hardware_dma

"

# ler bastas subpastas e arquivos
FIND_INC_H=$(find includes | grep "\.h")

FIND_LIB_H=$(find lib | grep "\.h")
FIND_LIB_C=$(find lib | grep "\.c")
FIND_SRC_C=$(find src | grep "\.c")

FIND_INCLUDES_D=$(find includes -type d)
FIND_LIB_D=$(find lib -type d)
FIND_SRC_D=$(find src -type d)


# gerar CMakeLists.txt
echo "## INIT ##


# NÃO MUDE ESTE ARQUIVO ELE É GERADO
# AUTOMATICAMENTE EM buils.sh

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)
set(PICO_SDK_PATH \"$PICO_SDK_PATH\")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(RPI_PICO_SDK C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executables. Default name is the project name, version 0.1

# Project directories
include_directories( 
$FIND_INCLUDES_D
$FIND_LIB_D
$FIND_SRC_D
)

# Project Files
add_executable( RPI_PICO_SDK
$FIND_SRC_C
$FIND_INC_H
$FIND_LIB_H
$FIND_LIB_C
)

pico_set_program_name(RPI_PICO_SDK \"RPI_PICO_SDK\")
pico_set_program_version(RPI_PICO_SDK "0.1")

pico_enable_stdio_uart(RPI_PICO_SDK 1)
pico_enable_stdio_usb(RPI_PICO_SDK 0)

# Add the standard library to the build
target_link_libraries(RPI_PICO_SDK pico_stdlib)

# Add any user requested libraries
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
