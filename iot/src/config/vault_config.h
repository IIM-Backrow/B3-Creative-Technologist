#ifndef VAULT_CONFIG_H
#define VAULT_CONFIG_H

#include <Arduino.h>

// Servo configuration
extern const int SERVO_PIN;
extern const int VAULT_OPEN_ANGLE;
extern const int VAULT_CLOSED_ANGLE;

// Vault state
extern String SECRET_CODE;
extern bool vaultOpen;

#endif