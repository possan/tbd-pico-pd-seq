cmake_minimum_required(VERSION 3.5)

set(ENV{PICO_SDK_PATH} "${CMAKE_SOURCE_DIR}/../../pico-sdk")
include(pico_sdk_import.cmake)

project(tbdpicoseq)

configure_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/test2.pd
  ${CMAKE_CURRENT_BINARY_DIR}/test2.pd
)

execute_process(
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMAND hvcc -o hv-out -n sequencerpatch test2.pd
)


add_subdirectory(lib/usb_midi_host)

FILE(GLOB HEAVY_SRC_FILES ${CMAKE_CURRENT_BINARY_DIR}/hv-out/c/*)

pico_sdk_init()

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-strict-aliasing -Wno-int-to-pointer-cast -Wno-unused-but-set-variable -Wno-unused-function -Wno-format -Wno-stringop-truncation -Wno-unused-const-variable -Wno-pointer-to-int-cast -Wimplicit-function-declaration -fno-delete-null-pointer-checks -Wcast-align -falign-functions=4 -falign-jumps=4 -falign-labels=4 -falign-loops=4")

set (CMAKE_CXX_STANDARD 20)
# add_compile_options(-mfloat-abi=softfp)
add_compile_options(-DHV_PICO -mfloat-abi=softfp)
# add_compile_options(-DHV_SIMD_NEON -mfloat-abi=softfp)

include_directories(
    tbdpicoseq
    gen/c
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_BINARY_DIR}/hv-out/c
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/usb_midi_host
)

add_executable(tbdpicoseq
    src/display.c
    src/i2c.c
    src/leds.c
    src/main.c
    src/pd_seq.c
    src/tbd.c
    src/ui_board.c
    src/usb_host.c
    src/m0FaultDispatch.c
    ${HEAVY_SRC_FILES}
)

target_link_libraries(tbdpicoseq LINK_PUBLIC
    pico_stdlib
    pico_multicore
    pico_sync
    hardware_i2c
    hardware_spi
    hardware_pio
    hardware_watchdog
    hardware_exception
    tinyusb_host
    tinyusb_board
    tinyusb_pico_pio_usb
    usb_midi_host_app_driver
)

pico_generate_pio_header(tbdpicoseq ${CMAKE_CURRENT_LIST_DIR}/src/ws2812.pio OUTPUT_DIR ${CMAKE_CURRENT_LIST_DIR}/generated)

# add_custom_command(OUTPUT ${CMAKE_CURRENT_LIST_DIR}/generated/ws2812.py
#         DEPENDS ${CMAKE_CURRENT_LIST_DIR}/ws2812.pio
#         COMMAND pioasm -o python ${CMAKE_CURRENT_LIST_DIR}/ws2812.pio ${CMAKE_CURRENT_LIST_DIR}/generated/ws2812.py
#         VERBATIM)

pico_enable_stdio_usb(tbdpicoseq 0)
pico_enable_stdio_uart(tbdpicoseq 1)
pico_add_extra_outputs(tbdpicoseq)
