file(GLOB hello_world_src "*.cpp")

add_executable(hello_world ${hello_world_src})

pico_enable_stdio_usb(hello_world 1)
pico_enable_stdio_uart(hello_world 0)

target_precompile_headers(hello_world PRIVATE "pch.hpp")
target_link_libraries(hello_world pico_stdlib)

pico_add_extra_outputs(hello_world)
