
# SPDX-License-Identifier: Apache-2.0

# NÃO MUDE ESTE ARQUIVO ELE É GERADO
# AUTOMATICAMENTE

cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS {ZEPHYR_BASE})

project(RPI_PICO)

target_sources(app PRIVATE 
src/modules/motor/motor.c
src/main.c
src/modules/motor/motor.h
) 
