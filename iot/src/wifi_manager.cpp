#include "wifi_manager.h"
#include "vault_config.h"

void initWiFi() {
  delay(1000);

  Serial.println("Connecting to WiFi");
  Serial.print("SSID: ");
  Serial.println(WIFI_SSID);
  Serial.print("Password: ");
  Serial.println(WIFI_PASSWORD);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Status: ");
  Serial.println(WiFi.status());

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("✅ WiFi connected!");
}

void printWiFiInfo() {
  Serial.print("📡 IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println("🔗 Server: http://" + WiFi.localIP().toString());
}