#include <device.h>
#include <gpio.h>
#include <sys_clock.h>
#include <zephyr.h>

#define GPIO_OUT_PIN 	2
#define GPIO_NAME 		"GPIO_SS_"
#define GPIO_DRV_NAME 	"GPIO_0"

/*
 * This program toggles PIN A0 so if you connect an LED to that pin you
 * should see something.
 */
void main(void)
{

	struct device *gpio_device;

	struct nano_timer timer;
	void *timer_data[1];

	int ret;
	int pin_state = 1;

	nano_timer_init(&timer, timer_data);

	gpio_device = device_get_binding(GPIO_DRV_NAME);
	if (!gpio_device) {
		return;
	}

	ret = gpio_pin_configure(gpio_device, GPIO_OUT_PIN, (GPIO_DIR_OUT));
	if (ret) {
		return;
	}

	while (1) {

		gpio_pin_write(gpio_device, GPIO_OUT_PIN, pin_state);

		pin_state = !pin_state;

		nano_timer_start(&timer, SECONDS(1));
		nano_timer_test(&timer, TICKS_UNLIMITED);
	}
}
