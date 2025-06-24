#include "motion_detector.h"
#include "led_controller.h"

const float SHAKE_THRESHOLD = 15;

Adafruit_MPU6050 mpu;

float lastAccelMagnitude = 0.0;

void initMotionDetector() {
  Wire.begin(MPU_SDA_PIN, MPU_SCL_PIN);
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

  for (int i = 0; i < 5; i++) {
    setLight(COLOR_RED);
    delay(200);
    setLight(COLOR_OFF);
    delay(200);
  }
}