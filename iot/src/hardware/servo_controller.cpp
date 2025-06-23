#include "servo_controller.h"
#include "../config/vault_config.h"

s3servo myServo;

void initServo() {
  myServo.attach(SERVO_PIN);
  closeVault(); // Start with vault closed
}

void openVault() {
  myServo.write(VAULT_OPEN_ANGLE);
  vaultOpen = true;
  Serial.println("🔓 Vault opened");
}

void closeVault() {
  myServo.write(VAULT_CLOSED_ANGLE);
  vaultOpen = false;
  Serial.println("🔒 Vault closed");
}