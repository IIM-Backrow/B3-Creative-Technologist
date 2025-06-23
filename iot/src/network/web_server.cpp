#include "web_server.h"
#include "../config/vault_config.h"
#include "../routes/unlock.h"
#include "../routes/setcode.h"
#include "../routes/status.h"

WebServer server(80);

void initWebServer() {
  // Configure web server routes with lambda functions to pass server reference
  server.on("/unlock", HTTP_GET, []() { handleUnlock(server); });
  server.on("/setcode", HTTP_GET, []() { handleSetCode(server); });
  server.on("/status", HTTP_GET, []() { handleStatus(server); });

  // Start server
  server.begin();
}

void printServerInfo() {
  Serial.println("🌐 HTTP server started on port 80");
  Serial.println("📋 Available routes:");
  Serial.println("   GET /unlock?code=XXXX                  - Unlock vault");
  Serial.println("   GET /setcode?oldcode=XXXX&newcode=YYYY - Change secret code");
  Serial.println("   GET /status                            - Vault status");
  Serial.println();
  Serial.println("🔑 Default secret code: " + SECRET_CODE);
}

void handleWebServerClients() {
  server.handleClient();
}