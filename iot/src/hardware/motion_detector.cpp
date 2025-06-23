#include "motion_detector.h"
#include "../config/notes.h"

const int MPU_SDA_PIN = 5;
const int MPU_SCL_PIN = 6;
const int SPEAKER_PIN = 7;

const float SHAKE_THRESHOLD = 2.5;
const unsigned long SHAKE_DEBOUNCE_TIME = 500;

Adafruit_MPU6050 mpu;

float lastAccelMagnitude = 0.0;
unsigned long lastShakeTime = 0;

void initMotionDetector() {
  Wire.begin(MPU_SDA_PIN, MPU_SCL_PIN);
  pinMode(SPEAKER_PIN, OUTPUT);

  if (!mpu.begin()) {
    Serial.println("❌ Failed to find MPU6050 chip");
    return;
  }

  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

  delay(100);
}

void updateMotionDetection() {
  sensors_event_t accel, gyro, temp;
  mpu.getEvent(&accel, &gyro, &temp);

  float currentMagnitude = calculateAccelMagnitude(accel);

  if (lastAccelMagnitude > 0) {
    float magnitudeChange = abs(currentMagnitude - lastAccelMagnitude);

    if (magnitudeChange > SHAKE_THRESHOLD &&
        (millis() - lastShakeTime) > SHAKE_DEBOUNCE_TIME) {
      onShake();
      lastShakeTime = millis();
    }
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

  // Play alert melody
  tone(SPEAKER_PIN, NOTE_A4, 500);
  tone(SPEAKER_PIN, NOTE_F4, 500);
  tone(SPEAKER_PIN, NOTE_D4, 500);

  // TODO: Add security protocol here (set leds in red)
}