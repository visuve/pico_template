#include "hello_world.pch"

enum pins : uint8_t {
	LED = PICO_DEFAULT_LED_PIN
};

int main() {
	stdio_init_all();

	gpio_init(pins::LED);
	gpio_set_dir(pins::LED, GPIO_OUT);

	int my_counter = 0;

	while (true) {
		bool led_on = ++my_counter % 2 == 0;
		gpio_put(pins::LED, led_on);
		printf("Hello, world!\n");
		sleep_ms(1000);
	}

	return 0;
}
