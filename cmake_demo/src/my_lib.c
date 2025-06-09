#include <stdio.h>
#include <zephyr/device.h>
#include <zephyr/sys/util.h>
#include <zephyr/sys/printk.h>

#include "my_lib.h"

void say_hello() {
    printk("Printk: Hello from my_lib\n");
    printf("Printf: Hello from my_lib\n");
}