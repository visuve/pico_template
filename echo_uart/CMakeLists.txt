file(GLOB echo_uart_src "*.cpp")

add_executable(echo_uart ${echo_uart_src})

pico_enable_stdio_usb(echo_uart 1)
pico_enable_stdio_uart(echo_uart 0)

target_precompile_headers(echo_uart PRIVATE "echo_uart.pch")
target_link_libraries(echo_uart pico_stdlib hardware_uart)

pico_add_extra_outputs(echo_uart)
