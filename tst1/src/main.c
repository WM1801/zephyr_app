#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/random/random.h>
#ifdef CONFIG_SAY_HELLO
#include "say_hello.h" 
#endif  

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
    double rnd_float; 

   
    while(1)
    {
        #ifdef CONFIG_SAY_HELLO
        say_hello();
        #endif
        ret = gpio_pin_toggle_dt(&led);
        rnd = sys_rand32_get();
        rnd_float = (double)rnd / (UINT32_MAX + 1.0);
        printf("Random number: %.5f\n", rnd_float);
        k_msleep(SLEEP_TIME_MS);
    }
   
    return 0;       
}