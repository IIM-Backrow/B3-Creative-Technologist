#include <Arduino.h>
#include "config/vault_config.h"
#include "network/wifi_manager.h"
#include "hardware/servo_controller.h"
#include "hardware/led_controller.h"
#include "network/web_server.h"
#include "hardware/motion_detector.h"

void setup() {
  Serial.begin(115200);
  Serial.readStringUntil('\n');

  Serial.println("🚀 Starting ESP32S3 Vault Control System");

  // Initialize LED first for visual feedback
  initLeds();

  // Initialize servo
  initServo();

  // Initialize motion detector
  initMotionDetector();

  // Connect to WiFi
  initWiFi();
  printWiFiInfo();

  // Initialize and start web server
  initWebServer();
  printServerInfo();
}

void loop() {
  handleWebServerClients();
  updateMotionDetection();
}