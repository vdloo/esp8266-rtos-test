/* ESP8266 RTOS test

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "driver/gpio.h"

#include "esp_system.h"
#include "esp_spi_flash.h"

#define GPIO_OUTPUT_IO_LED 2
#define GPIO_OUTPUT_PIN_SEL  (1ULL<<GPIO_OUTPUT_IO_LED)
#define BLINK_DELAY_IN_MS 500

void app_main()
{
    printf("Blinking the built-in LED");

    gpio_config_t io_conf;
    io_conf.intr_type = GPIO_INTR_DISABLE;
    io_conf.mode = GPIO_MODE_OUTPUT;
    io_conf.pin_bit_mask = GPIO_OUTPUT_PIN_SEL;
    io_conf.pull_down_en = 0;
    io_conf.pull_up_en = 0;
    gpio_config(&io_conf);

    gpio_set_direction(GPIO_OUTPUT_IO_LED, GPIO_MODE_OUTPUT);

    while(1) {
        printf("Turning LED on\n");
        gpio_set_level(GPIO_OUTPUT_IO_LED, 0);

        vTaskDelay(BLINK_DELAY_IN_MS / portTICK_PERIOD_MS);

        printf("Turning LED off\n");
        gpio_set_level(GPIO_OUTPUT_IO_LED, 1);

        vTaskDelay(BLINK_DELAY_IN_MS / portTICK_PERIOD_MS);
    }
}
