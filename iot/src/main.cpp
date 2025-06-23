#include <Arduino.h>
#include "vault_config.h"
#include "wifi_manager.h"
#include "servo_controller.h"
#include "web_server.h"

void setup() {
  Serial.begin(115200);
  Serial.readStringUntil('\n');

  Serial.println("🚀 Starting ESP32S3 Vault Control System");

  // Initialize servo
  initServo();

  // Connect to WiFi
  initWiFi();
  printWiFiInfo();

  // Initialize and start web server
  initWebServer();
  printServerInfo();
}

void loop() {
  handleWebServerClients();
}