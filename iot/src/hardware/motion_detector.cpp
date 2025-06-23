#include "motion_detector.h"
#include "../config/notes.h"
#include "led_controller.h"
#include "megalovania.h"

const int MPU_SDA_PIN = 5;
const int MPU_SCL_PIN = 6;
const int SPEAKER_PIN = 7;

const float SHAKE_THRESHOLD = 10;

Adafruit_MPU6050 mpu;

float lastAccelMagnitude = 0.0;

void initMotionDetector() {
  Wire.begin(MPU_SDA_PIN, MPU_SCL_PIN);
  pinMode(SPEAKER_PIN, OUTPUT);

  mpu.begin();

  delay(100);
}

void updateMotionDetection() {
  sensors_event_t accel, gyro, temp;
  mpu.getEvent(&accel, &gyro, &temp);

  float currentMagnitude = calculateAccelMagnitude(accel);

  if (lastAccelMagnitude > 0 &&
      abs(currentMagnitude - lastAccelMagnitude) > SHAKE_THRESHOLD) {
    onShake();
  }

  lastAccelMagnitude = currentMagnitude;
}

float calculateAccelMagnitude(sensors_event_t& accel) {
  return sqrt(pow(accel.acceleration.x, 2) +
              pow(accel.acceleration.y, 2) +
              pow(accel.acceleration.z, 2));
}

void onShake() {
  Serial.println("🚨 SHAKE DETECTED! Security alert triggered!");

  setLight(COLOR_RED);
  playSecurityAlarm();
  setLight(COLOR_OFF);
}