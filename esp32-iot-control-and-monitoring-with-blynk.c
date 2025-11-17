#include "freertos/FreeRTOS.h" // FreeRTOS
#include "freertos/task.h" // Tasks
#include "driver/gpio.h" // GPIO
#include "esp_log.h" // Logging

#define LED_GPIO GPIO_NUM_2 // LED
static const char *TAG = "BLYNK"; // Tag

void app_main(void) { // Entry
  gpio_set_direction(LED_GPIO, GPIO_MODE_OUTPUT); // LED out
  ESP_LOGI(TAG, "Blynk demo placeholder"); // Log
  while (true) { // Loop
    gpio_set_level(LED_GPIO, 1); // LED on
    vTaskDelay(pdMS_TO_TICKS(500)); // Delay
    gpio_set_level(LED_GPIO, 0); // LED off
    vTaskDelay(pdMS_TO_TICKS(500)); // Delay
  } // End loop
} // End app_main

