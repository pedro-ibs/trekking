#! /bin/bash


export PICO_SDK_PATH=/home/pibs/.local/opt/pico/pico-sdk
export PICO_EXAMPLES_PATH=/home/pibs/.local/opt/pico/pico-examples
export PICO_EXTRAS_PATH=/home/pibs/.local/opt/pico/pico-extras
export PICO_PLAYGROUND_PATH=/home/pibs/.local/opt/pico/pico-playground
export PICO_PLATFORM=rp2040



FIND_INC_H=$(find includes | grep "\.h")

FIND_LIB_H=$(find lib | grep "\.h")
FIND_LIB_C=$(find lib | grep "\.c")
FIND_SRC_C=$(find src | grep "\.c")

FIND_INCLUDES_D=$(find includes -type d)
FIND_LIB_D=$(find lib -type d)
FIND_SRC_D=$(find src -type d)

echo "## INIT ##


# NÃO MUDE ESTE ARQUIVO ELE É GERADO
# AUTOMATICAMENTE

cmake_minimum_required(VERSION 3.12)
include(pico_sdk_import.cmake)


project( RPI_PICO_SDK )

pico_sdk_init()

include_directories( 
$FIND_INCLUDES_D
$FIND_LIB_D
$FIND_SRC_D
)

add_executable( RPI_PICO_SDK
$FIND_SRC_C
$FIND_INC_H
$FIND_LIB_H
$FIND_LIB_C
)

# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(RPI_PICO_SDK pico_stdlib)
  
# create map/bin/hex file etc.
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