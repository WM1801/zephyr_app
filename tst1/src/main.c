#include "my_lib.h"
#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/random/random.h>


#define SLEEP_TIME_MS   1000

/*led, gpio out*/
#define GPIO05_NODE DT_ALIAS(gpio05)
static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(GPIO05_NODE, gpios);
int main(void) {

    // led 
    int ret = 0;
    bool led_state = true;

    if (!gpio_is_ready_dt(&led)) {
        return 0;
    }
    ret = gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE);
    printk("initialize GPIO05 - ok\n");
    if (ret < 0) {
        printk("Failed to initialize GPIO05\n");
        return 0;
    }
    //rnd 
    uint32_t rnd; 


   
    while(1)
    {
        say_hello();
        ret = gpio_pin_toggle_dt(&led);
        rnd = sys_rand32_get();
        printk("Random number: %u\n", rnd);
        k_msleep(SLEEP_TIME_MS);
    }
   
    return 0;       
}