#include "echo_irq.pch" 

enum pins : uint8_t {
	TRIGGER = 2
};

void gpio_callback(uint gpio, uint32_t events) {
	if (gpio == pins::TRIGGER) {
		printf("IRQ triggered on pin %d! Event mask: %04X\n", gpio, events);
	}
}

int main() {
	stdio_init_all();

	gpio_init(pins::TRIGGER);
	gpio_set_dir(pins::TRIGGER, GPIO_IN);
	gpio_pull_up(pins::TRIGGER);

	gpio_set_irq_enabled_with_callback(pins::TRIGGER, GPIO_IRQ_EDGE_FALL, true, &gpio_callback);

	while (true) {
		tight_loop_contents();
	}

	return 0;
}