#include "wifi_manager.h"
#include "vault_config.h"

// Access Point configuration
const char* AP_SSID = "SecureVault";
const char* AP_PASSWORD = "";

void initWiFi() {
  delay(1000);

  Serial.println("🔧 Creating WiFi Access Point...");
  Serial.print("📡 SSID: ");
  Serial.println(AP_SSID);
  Serial.println("🔓 Password: <None>");

  // Create Access Point
  bool success = WiFi.softAP(AP_SSID, AP_PASSWORD);

  if (success) {
    Serial.println("✅ Access Point created successfully!");
  } else {
    Serial.println("❌ Failed to create Access Point!");
    return;
  }

  delay(1000); // Give AP time to start
}

void printWiFiInfo() {
  IPAddress apIP = WiFi.softAPIP();
  Serial.print("📡 Access Point IP: http://");
  Serial.println(apIP);
  Serial.print("🌐 Connect to network: ");
  Serial.println(AP_SSID);
}