# SPDX-License-Identifier: Apache-2.0


cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})



project(RPIPICO)

FILE(GLOB app_sources CONFIGURE_DEPENDS src/*.c src/*.h motor/*.c motor/*.h )

target_sources(app PUBLIC src/main.c motor/motor.c motor/motor.h )
