#include "unlock.h"
#include "../config/vault_config.h"
#include "../hardware/servo_controller.h"

void handleUnlock(WebServer &server) {
  String code = "";

  // Check if code is in query parameter
  if (server.hasArg("code")) {
    code = server.arg("code");
  } else {
    server.send(400, "application/json",
      "{\"status\":\"error\",\"message\":\"Missing code parameter\"}");
    return;
  }

  Serial.print("Received code: ");
  Serial.println(code);

  // Validate code
  if (code == SECRET_CODE) {
    // Correct code - open vault
    openVault();

    server.send(200, "application/json",
      "{\"status\":\"success\",\"message\":\"Vault opened\",\"code\":\"" + code + "\"}");

    // Close vault after 2 seconds
    delay(2000);
    closeVault();

    Serial.println("✅ Access granted - Vault cycle completed");
  } else {
    // Wrong code
    server.send(401, "application/json",
      "{\"status\":\"error\",\"message\":\"Invalid code\",\"code\":\"" + code + "\"}");

    Serial.println("❌ Access denied - Invalid code");
  }
}