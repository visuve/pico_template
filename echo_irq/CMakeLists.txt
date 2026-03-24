file(GLOB echo_irq_src "*.cpp")

add_executable(echo_irq ${echo_irq_src})

pico_enable_stdio_usb(echo_irq 1)
pico_enable_stdio_uart(echo_irq 0)

target_precompile_headers(echo_irq PRIVATE "echo_irq.pch")
target_link_libraries(echo_irq pico_stdlib hardware_gpio)

pico_add_extra_outputs(echo_irq)
