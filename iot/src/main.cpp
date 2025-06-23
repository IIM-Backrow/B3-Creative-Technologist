#include <Arduino.h>

#define SERVO_PIN 10

void setup() {
  Serial.begin(115200);
  Serial.println("Hello, World!");
  pinMode(SERVO_PIN, OUTPUT);
}

void loop() {
  digitalWrite(SERVO_PIN, HIGH);
  delay(1000);
  digitalWrite(SERVO_PIN, LOW);
  delay(1000);
}