#include "echo_spi.pch"

enum pins : uint8_t {
	MISO = PICO_DEFAULT_SPI_RX_PIN,
	CS   = PICO_DEFAULT_SPI_CSN_PIN,
	SCK  = PICO_DEFAULT_SPI_SCK_PIN,
	MOSI = PICO_DEFAULT_SPI_TX_PIN
};

spi_inst_t* const SPI_PORT = spi0;
constexpr uint32_t BAUD_RATE = 1000 * 1000; // 1 MHz
constexpr size_t BUFFER_SIZE = 4;

int main() {
	stdio_init_all();

	spi_init(SPI_PORT, BAUD_RATE);

	gpio_set_function(pins::SCK,  GPIO_FUNC_SPI);
	gpio_set_function(pins::MOSI, GPIO_FUNC_SPI);
	gpio_set_function(pins::MISO, GPIO_FUNC_SPI);

	gpio_init(pins::CS);
	gpio_set_dir(pins::CS, GPIO_OUT);
	gpio_put(pins::CS, true);

	uint8_t rx_buffer[BUFFER_SIZE];

	while (true) {
		gpio_put(pins::CS, false);
		spi_read_blocking(SPI_PORT, 0x00, rx_buffer, BUFFER_SIZE);
		gpio_put(pins::CS, true);

		for (uint8_t i = 0; i < BUFFER_SIZE; ++i) {
			printf("%02X ", rx_buffer[i]);
		}
		printf("\n");

		sleep_ms(1000);
	}

	return 0;
}