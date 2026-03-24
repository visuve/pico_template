file(GLOB echo_spi_src "*.cpp")

add_executable(echo_spi ${echo_spi_src})

pico_enable_stdio_usb(echo_spi 1)
pico_enable_stdio_uart(echo_spi 0)

target_precompile_headers(echo_spi PRIVATE "echo_spi.pch")
target_link_libraries(echo_spi pico_stdlib hardware_spi)

pico_add_extra_outputs(echo_spi)
