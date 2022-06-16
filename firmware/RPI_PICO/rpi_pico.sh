#! /bin/bash

export ZEPHYR_BASE=$HOME/zephyrproject/zephyr/
# export ZEPHYR_TOOLCHAIN_VARIANT=
# export ESPRESSIF_TOOLCHAIN_PATH=


FIND_FILES_H=$(find src | grep "\.h")
FIND_FILES_C=$(find src | grep "\.c")

echo "
# SPDX-License-Identifier: Apache-2.0

# NÃO MUDE ESTE ARQUIVO ELE É GERADO
# AUTOMATICAMENTE

cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

project(RPI_PICO)

target_sources(app PRIVATE 
$FIND_FILES_C
$FIND_FILES_H
) " > CMakeLists.txt

west build -b rpi_pico $1
cd build
ninja hardenconfig

scp zephyr/zephyr.elf tars@tracker.local:trekking/rpi_pico.elf
ssh tars@tracker.local 'cd $HOME/trekking && openocd -f interface/raspberrypi-swd.cfg -f target/rp2040.cfg -c "program rpi_pico.elf verify reset exit"'
