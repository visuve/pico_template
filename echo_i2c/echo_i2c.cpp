#include "echo_i2c.pch"

enum pins : uint8_t {
	SDA = PICO_DEFAULT_I2C_SDA_PIN,
	SCL = PICO_DEFAULT_I2C_SCL_PIN
};

constexpr i2c_inst_t* I2C = i2c0;
constexpr uint32_t BAUD_RATE = 100 * 1000;
constexpr uint8_t I2C_ADDRESS = 0x68;
constexpr size_t BUFFER_SIZE = 4;

int main() {
	stdio_init_all();

	i2c_init(I2C, BAUD_RATE);

	gpio_set_function(pins::SDA, GPIO_FUNC_I2C);
	gpio_set_function(pins::SCL, GPIO_FUNC_I2C);

	gpio_pull_up(pins::SDA);
	gpio_pull_up(pins::SCL);

	uint8_t rx_buffer[BUFFER_SIZE];

	while (true) {
		i2c_read_blocking(I2C, I2C_ADDRESS, rx_buffer, BUFFER_SIZE, false);

		for (uint8_t i = 0; i < BUFFER_SIZE; ++i) {
			printf("%02X ", rx_buffer[i]);
		}
		printf("\n");

		sleep_ms(1000);
	}

	return 0;
}