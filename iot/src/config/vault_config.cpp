#include "vault_config.h"

// Servo configuration
const int SERVO_PIN = 9;
const int VAULT_OPEN_ANGLE = 180;
const int VAULT_CLOSED_ANGLE = 0;

// Vault state
String SECRET_CODE = "1234"; // Default 4-digit secret code (changeable)
bool vaultOpen = false;