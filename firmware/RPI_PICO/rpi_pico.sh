#! /bin/bash
export ZEPHYR_BASE=$HOME/zephyrproject/zephyr/
# export ZEPHYR_TOOLCHAIN_VARIANT=
# export ESPRESSIF_TOOLCHAIN_PATH=

west build -b rpi_pico $1
cd build
ninja hardenconfig


scp zephyr/zephyr.elf tars@tracker.local:trekking/rpi_pico.elf 
ssh tars@tracker.local 'cd $HOME/trekking && openocd -f interface/raspberrypi-swd.cfg -f target/rp2040.cfg -c "program rpi_pico.elf verify reset exit"'

