#! /bin/bash

scp build/RPI_PICO_SDK.elf tars@voyager.local:rpi_pico.elf
ssh tars@voyager.local 'openocd -f interface/raspberrypi-swd.cfg -f target/rp2040.cfg -c "program rpi_pico.elf verify reset exit"'