#include "servo_controller.h"
#include "../config/vault_config.h"
#include "led_controller.h"

s3servo myServo;

void initServo() {
  myServo.attach(SERVO_PIN);
  closeVault(); // Start with vault closed
}

void openVault() {
  myServo.write(VAULT_OPEN_ANGLE);
  vaultOpen = true;
  setLight(COLOR_GREEN);
  Serial.println("🔓 Vault opened");
}

void closeVault() {
  myServo.write(VAULT_CLOSED_ANGLE);
  vaultOpen = false;
  setLight(COLOR_OFF);
  Serial.println("🔒 Vault closed");
}