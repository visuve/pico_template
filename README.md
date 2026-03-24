# pico-templates

- Small C++ examples for Raspberry Pi Pico to get things going
- See more examples in https://github.com/raspberrypi/pico-examples

# How to init

- Clone the repo
- Recursively update submodules
	- The pico-sdk is a must and contains more submodules

# How to build (Windows)

- Install Visual Studio 2026 Community Edition
	- https://visualstudio.microsoft.com/downloads/
	- Make sure Linux, Mac and embedded development with C++ is selected
- (OPTIONAL) if you do want to install Visual Studio, install CMake, make sure it is in PATH and use whatever IDE/Editor you want
	- https://cmake.org/download/
- Install Python
	- https://visualstudio.microsoft.com/downloads/
- Install ARM GNU Toolchain
	- https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads
	- Grab latest ``arm-gnu-toolchain-XX.X.relX-mingw-w64-x86_64-arm-none-eabi.msi``
	- Add the bin folder in PATH
- Open this project folder in Visual Studio
- Select target to ``hello_world.elf``

# How to run

- Press "BOOTSEL" button on the Pico
- Connect USB cable or reset Pico (short pin 30 "RUN" to GND)
- See a partition RPI-RP2 appear
- Drag & drop the ``hello_world.uf2`` on to the partition
- The device should now boot itself

# How to debug

- Use a serial monitoring tool like Putty to read the COM port where the Pico is attached to
	- In Windows this can be found in Device Manager and under Ports (COM & LPT), usually COM4
- This example uses USB and not UART so the baud rate does not matter
