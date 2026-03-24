#include "echo_uart.pch"

enum pins : uint8_t {
	RX = 1
};

uart_inst_t* const UART = uart0;
constexpr uint32_t BAUD_RATE = 115200;

int main() {
	stdio_init_all();

	uart_init(UART, BAUD_RATE);
	gpio_set_function(pins::RX, GPIO_FUNC_UART);

	while (true) {
		if (uart_is_readable(UART)) {
			char c = uart_getc(UART);
			putchar(c);
		}
	}

	return 0;
}