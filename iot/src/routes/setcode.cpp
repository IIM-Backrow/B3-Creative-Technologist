#include "setcode.h"
#include "../vault_config.h"

void handleSetCode(WebServer &server) {
  String oldCode = "";
  String newCode = "";

  // Check required parameters
  if (server.hasArg("oldcode")) {
    oldCode = server.arg("oldcode");
  } else {
    server.send(400, "application/json",
      "{\"status\":\"error\",\"message\":\"Missing oldcode parameter\"}");
    return;
  }

  if (server.hasArg("newcode")) {
    newCode = server.arg("newcode");
  } else {
    server.send(400, "application/json",
      "{\"status\":\"error\",\"message\":\"Missing newcode parameter\"}");
    return;
  }

  Serial.print("Change code request - Old: ");
  Serial.print(oldCode);
  Serial.print(", New: ");
  Serial.println(newCode);

  // Validate old code
  if (oldCode != SECRET_CODE) {
    server.send(401, "application/json",
      "{\"status\":\"error\",\"message\":\"Invalid old code\"}");
    Serial.println("❌ Code change denied - Invalid old code");
    return;
  }

  // Validate new code format (4 digits)
  if (newCode.length() != 4 || !newCode.equals(String(newCode.toInt()).substring(0, 4))) {
    server.send(400, "application/json",
      "{\"status\":\"error\",\"message\":\"New code must be 4 digits\"}");
    Serial.println("❌ Code change denied - Invalid new code format");
    return;
  }

  // Update secret code
  SECRET_CODE = newCode;

  server.send(200, "application/json",
    "{\"status\":\"success\",\"message\":\"Code changed successfully\",\"newcode\":\"" + newCode + "\"}");

  Serial.println("✅ Secret code changed successfully to: " + newCode);
}