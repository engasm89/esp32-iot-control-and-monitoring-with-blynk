/*
 * Course: Esp32 Iot Control And Monitoring With Blynk
 * Platform: ESP32
 * Author: Ashraf S A AlMadhoun
 * 
 * Description:
 * This code demonstrates the core concepts taught in the "Esp32 Iot Control And Monitoring With Blynk" course.
 * It provides a practical implementation that students can study, modify, and
 * use as a foundation for their own projects.
 * 
 * Learning Objectives:
 * - Understand the fundamental principles covered in this course
 * - Practice implementing the concepts with real code
 * - Build a working example that can be extended
 * 
 * Hardware Requirements:
 * - Development board (ESP32)
 * - Components as specified in CIRCUIT.md
 * - USB cable for programming
 * 
 * Pin Connections:
 * Refer to CIRCUIT.md for detailed wiring diagrams and pin assignments.
 * 
 * Usage:
 * 1. Review the code structure and comments
 * 2. Connect hardware according to CIRCUIT.md
 * 3. Upload code to your development board
 * 4. Monitor serial output for debugging
 * 
 * Course Link: https://www.udemy.com/course/esp32-iot-control-and-monitoring-with-blynk/
 * Repository: https://github.com/engasm89/esp32-iot-control-and-monitoring-with-blynk
 * 
 * Copyright (c) 2025 Ashraf S A AlMadhoun
 * Licensed under MIT License
 */

#include "freertos/FreeRTOS.h" // FreeRTOS
#include "freertos/task.h" // Tasks
#include "driver/gpio.h" // GPIO
#include "esp_log.h" // Logging

#define LED_GPIO GPIO_NUM_2 // LED
static const char *TAG = "BLYNK"; // Tag
static int mode = 0; // LED mode commanded by cloud (simulated)

void app_main(void) { // Program entry point
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
} // End of main function

