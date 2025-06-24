#include <Arduino.h>
#include "config/vault_config.h"
#include "network/wifi_manager.h"
#include "hardware/servo_controller.h"
#include "hardware/led_controller.h"
#include "network/web_server.h"
#include "hardware/motion_detector.h"
#include "hardware/button_controller.h"

void setup() {
  Serial.begin(115200);
  Serial.readStringUntil('\n');

  Serial.println("🚀 Starting ESP32S3 Vault Control System");

  initLeds();
  initServo();
  initMotionDetector();
  initButtons();

  initWiFi();
  printWiFiInfo();

  initWebServer();
  printServerInfo();
}

void loop() {
  handleWebServerClients();
  updateMotionDetection();
  updateButtons();
}