#include <atmel_start.h>
#include "led_driver.h"

extern volatile uint8_t measurement_done_touch;

int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();

	init_led_driver();
	led_reset();

	/* Replace with your application code */
	while (1) {
		touch_process();

		if (measurement_done_touch == 1u) {
			measurement_done_touch = 0;
			led_decode_and_update();
		}
	}
}
