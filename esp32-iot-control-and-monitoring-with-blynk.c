#include "freertos/FreeRTOS.h" // FreeRTOS
#include "freertos/task.h" // Tasks
#include "driver/gpio.h" // GPIO
#include "esp_log.h" // Logging

#define LED_GPIO GPIO_NUM_2 // LED
static const char *TAG = "BLYNK"; // Tag
static int mode = 0; // LED mode commanded by cloud (simulated)

void app_main(void) { // Entry
  gpio_set_direction(LED_GPIO, GPIO_MODE_OUTPUT); // LED out
  ESP_LOGI(TAG, "Blynk control and monitoring demo"); // Log
  int tick = 0; // Tick counter
  while (true) { // Loop
    tick++; // Increment tick
    if (tick % 20 == 0) { // Simulate cloud command every 20 ticks
      mode = (mode + 1) % 3; // Cycle mode
      ESP_LOGI(TAG, "Cloud command: mode=%d", mode); // Log
    } // End cloud command emulation
    if (mode == 0) { // Blink
      gpio_set_level(LED_GPIO, 1); vTaskDelay(pdMS_TO_TICKS(200)); gpio_set_level(LED_GPIO, 0); vTaskDelay(pdMS_TO_TICKS(200));
    } else if (mode == 1) { // Quick pulse
      gpio_set_level(LED_GPIO, 1); vTaskDelay(pdMS_TO_TICKS(50)); gpio_set_level(LED_GPIO, 0); vTaskDelay(pdMS_TO_TICKS(400));
    } else { // Steady ON
      gpio_set_level(LED_GPIO, 1); vTaskDelay(pdMS_TO_TICKS(500));
    } // End mode selection
  } // End loop
} // End app_main

