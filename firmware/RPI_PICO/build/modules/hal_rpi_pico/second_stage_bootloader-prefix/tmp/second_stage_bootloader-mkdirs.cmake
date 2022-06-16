# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/pibs/zephyrproject/zephyr/modules/hal_rpi_pico/bootloader"
  "/home/pibs/workspace/trekking/firmware/RPI_PICO/build/bootloader"
  "/home/pibs/workspace/trekking/firmware/RPI_PICO/build/modules/hal_rpi_pico/second_stage_bootloader-prefix"
  "/home/pibs/workspace/trekking/firmware/RPI_PICO/build/modules/hal_rpi_pico/second_stage_bootloader-prefix/tmp"
  "/home/pibs/workspace/trekking/firmware/RPI_PICO/build/modules/hal_rpi_pico/second_stage_bootloader-prefix/src/second_stage_bootloader-stamp"
  "/home/pibs/workspace/trekking/firmware/RPI_PICO/build/modules/hal_rpi_pico/second_stage_bootloader-prefix/src"
  "/home/pibs/workspace/trekking/firmware/RPI_PICO/build/modules/hal_rpi_pico/second_stage_bootloader-prefix/src/second_stage_bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/pibs/workspace/trekking/firmware/RPI_PICO/build/modules/hal_rpi_pico/second_stage_bootloader-prefix/src/second_stage_bootloader-stamp/${subDir}")
endforeach()
