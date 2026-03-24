#include "pch.hpp"

int main() {
	stdio_init_all();

	gpio_init(PICO_DEFAULT_LED_PIN);
	gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);

	int my_counter = 0;

	while (true) {
		bool led_on = ++my_counter % 2 == 0;
		gpio_put(PICO_DEFAULT_LED_PIN, led_on);
		printf("Hello, world!\n");
		sleep_ms(1000);
	}

	return 0;
}