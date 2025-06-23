#include "led_controller.h"

// LED configuration
const int LED_PIN = 4;
const int LED_COUNT = 1;

// Color definitions (RGB values)
const uint32_t COLOR_RED = 0xFF0000;
const uint32_t COLOR_GREEN = 0x00FF00;
const uint32_t COLOR_BLUE = 0x0000FF;
const uint32_t COLOR_YELLOW = 0xFFFF00;
const uint32_t COLOR_PURPLE = 0xFF00FF;
const uint32_t COLOR_CYAN = 0x00FFFF;
const uint32_t COLOR_WHITE = 0xFFFFFF;
const uint32_t COLOR_OFF = 0x000000;

// NeoPixel object
Adafruit_NeoPixel pixels(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void initLeds() {
  pixels.begin();
  pixels.clear();
  pixels.show();

  Serial.println("✅ NeoPixel LED initialized on pin " + String(LED_PIN));

  // Test sequence: Red -> Green -> Blue -> Off
  setLight(COLOR_RED);
  delay(200);
  setLight(COLOR_GREEN);
  delay(200);
  setLight(COLOR_BLUE);
  delay(200);
  setLight(COLOR_OFF);

  Serial.println("🌈 LED test sequence completed");
}

void setLight(uint32_t color) {
  pixels.setPixelColor(0, color);
  pixels.show();
}

void setLight(uint8_t red, uint8_t green, uint8_t blue) {
  uint32_t color = pixels.Color(red, green, blue);
  setLight(color);
}