# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/pibs/.local/opt/pico/pico-sdk/tools/pioasm"
  "/home/pibs/workspace/trekking/firmware/RPI_PICO_SDK/build/pioasm"
  "/home/pibs/workspace/trekking/firmware/RPI_PICO_SDK/build/pico-sdk/src/rp2_common/cyw43_driver/pioasm"
  "/home/pibs/workspace/trekking/firmware/RPI_PICO_SDK/build/pico-sdk/src/rp2_common/cyw43_driver/pioasm/tmp"
  "/home/pibs/workspace/trekking/firmware/RPI_PICO_SDK/build/pico-sdk/src/rp2_common/cyw43_driver/pioasm/src/PioasmBuild-stamp"
  "/home/pibs/workspace/trekking/firmware/RPI_PICO_SDK/build/pico-sdk/src/rp2_common/cyw43_driver/pioasm/src"
  "/home/pibs/workspace/trekking/firmware/RPI_PICO_SDK/build/pico-sdk/src/rp2_common/cyw43_driver/pioasm/src/PioasmBuild-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/pibs/workspace/trekking/firmware/RPI_PICO_SDK/build/pico-sdk/src/rp2_common/cyw43_driver/pioasm/src/PioasmBuild-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/pibs/workspace/trekking/firmware/RPI_PICO_SDK/build/pico-sdk/src/rp2_common/cyw43_driver/pioasm/src/PioasmBuild-stamp${cfgdir}") # cfgdir has leading slash
endif()
