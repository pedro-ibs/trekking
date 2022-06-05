#! /bin/bash
export ZEPHYR_BASE=$HOME/zephyrproject/zephyr/
# export ZEPHYR_TOOLCHAIN_VARIANT=
# export ESPRESSIF_TOOLCHAIN_PATH=

west build auto -b arduino_nano_33_ble_sense $1
cd build
ninja hardenconfig
west flash --bossac="$HOME/.arduino15/packages/arduino/tools/bossac/1.9.1-arduino2/bossac"