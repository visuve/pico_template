file(GLOB echo_i2c_src "*.cpp")

add_executable(echo_i2c ${echo_i2c_src})

pico_enable_stdio_usb(echo_i2c 1)
pico_enable_stdio_uart(echo_i2c 0)

target_precompile_headers(echo_i2c PRIVATE "echo_i2c.pch")
target_link_libraries(echo_i2c pico_stdlib hardware_i2c)

pico_add_extra_outputs(echo_i2c)
