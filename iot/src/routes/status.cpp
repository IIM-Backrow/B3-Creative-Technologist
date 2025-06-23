#include "status.h"
#include "../vault_config.h"

void handleStatus(WebServer &server) {
  String status = vaultOpen ? "open" : "closed";
  server.send(200, "application/json",
    "{\"status\":\"" + status + "\",\"message\":\"Vault status\"}");
}