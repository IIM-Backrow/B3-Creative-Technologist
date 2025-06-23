#ifndef LED_CONTROLLER_H
#define LED_CONTROLLER_H

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

// LED configuration
extern const int LED_PIN;
extern const int LED_COUNT;

// Color definitions (RGB values)
extern const uint32_t COLOR_RED;
extern const uint32_t COLOR_GREEN;
extern const uint32_t COLOR_BLUE;
extern const uint32_t COLOR_YELLOW;
extern const uint32_t COLOR_PURPLE;
extern const uint32_t COLOR_CYAN;
extern const uint32_t COLOR_WHITE;
extern const uint32_t COLOR_OFF;

// NeoPixel object
extern Adafruit_NeoPixel pixels;

// Function declarations
void initLeds();
void setLight(uint32_t color);
void setLight(uint8_t red, uint8_t green, uint8_t blue);

#endif