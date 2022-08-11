## INIT ##


# NÃO MUDE ESTE ARQUIVO ELE É GERADO
# AUTOMATICAMENTE

cmake_minimum_required(VERSION 3.12)
include(pico_sdk_import.cmake)


project( RPI_PICO_SDK )

pico_sdk_init()

include_directories( 
includes
lib
lib/motor
lib/textProtocol
lib/uart
src
)

add_executable( RPI_PICO_SDK
src/main.c
includes/config.h
includes/hardware.h
lib/motor/motor.h
lib/textProtocol/textProtocol.h
lib/uart/simple_uart.h
lib/motor/motor.c
lib/textProtocol/textProtocol.c
lib/uart/simple_uart.c
)

# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(RPI_PICO_SDK pico_stdlib)
  
# create map/bin/hex file etc.
pico_add_extra_outputs(RPI_PICO_SDK)

## END ##
