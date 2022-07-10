#! /bin/bash

export ZEPHYR_BASE=$HOME/zephyrproject/zephyr/
# export ZEPHYR_TOOLCHAIN_VARIANT=
# export ESPRESSIF_TOOLCHAIN_PATH=

FIND_INC_H=$(find includes | grep "\.h")
FIND_LIB_H=$(find lib | grep "\.h")
FIND_LIB_C=$(find lib | grep "\.c")
FIND_SRC_C=$(find src | grep "\.c")

FIND_INCLUDES_D=$(find includes -type d)
FIND_LIB_D=$(find lib -type d)
FIND_SRC_D=$(find src -type d)


echo "
# SPDX-License-Identifier: Apache-2.0

# NÃO MUDE ESTE ARQUIVO ELE É GERADO
# AUTOMATICAMENTE

cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

project(RPI_PICO)

include_directories( 
$FIND_INCLUDES_D
$FIND_LIB_D
$FIND_SRC_D
)

target_sources(app PRIVATE
$FIND_SRC_C
$FIND_INC_H
$FIND_LIB_H
$FIND_LIB_C
) " > CMakeLists.txt

west build -b rpi_pico $1
cd build
ninja hardenconfig

# scp zephyr/zephyr.elf tars@tracker.local:trekking/rpi_pico.elf
# ssh tars@tracker.local 'cd $HOME/trekking && openocd -f interface/raspberrypi-swd.cfg -f target/rp2040.cfg -c "program rpi_pico.elf verify reset exit"'
