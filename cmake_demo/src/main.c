#include "my_lib.h"
#include <zephyr/kernel.h>

int main(void) {
   
    while(1)
    {
        say_hello();
        k_msleep(1000);
    }
   
    return 0;       
}