#! /bin/bash

scp .pio/build/pico/firmware.elf tars@tracker.local:trekking/rpi_pico.elf
ssh tars@tracker.local 'cd $HOME/trekking && openocd -f interface/raspberrypi-swd.cfg -f target/rp2040.cfg -c "program rpi_pico.elf verify reset exit"'