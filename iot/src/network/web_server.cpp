#include "web_server.h"
#include "../config/vault_config.h"
#include "../routes/unlock.h"
#include "../routes/setcode.h"
#include "../routes/status.h"

WebServer server(80);

void setCORSHeaders() {
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.sendHeader("Access-Control-Allow-Methods", "GET, POST, PUT, DELETE, OPTIONS");
  server.sendHeader("Access-Control-Allow-Headers", "*");
  server.sendHeader("Access-Control-Max-Age", "86400");
}

void initWebServer() {
  // Configure CORS preflight handler
  server.on("/unlock", HTTP_OPTIONS, []() {
    setCORSHeaders();
    server.send(204);
  });
  server.on("/setcode", HTTP_OPTIONS, []() {
    setCORSHeaders();
    server.send(204);
  });
  server.on("/status", HTTP_OPTIONS, []() {
    setCORSHeaders();
    server.send(204);
  });

    // Configure web server routes with lambda functions to pass server reference
  server.on("/unlock", HTTP_GET, []() {
    setCORSHeaders();
    handleUnlock(server);
  });
  server.on("/setcode", HTTP_GET, []() {
    setCORSHeaders();
    handleSetCode(server);
  });
  server.on("/status", HTTP_GET, []() {
    setCORSHeaders();
    handleStatus(server);
  });

  // Catch-all OPTIONS handler for CORS preflight
  server.onNotFound([]() {
    if (server.method() == HTTP_OPTIONS) {
      setCORSHeaders();
      server.send(204);
    } else {
      setCORSHeaders();
      server.send(404, "application/json", "{\"status\":\"error\",\"message\":\"Not found\"}");
    }
  });

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