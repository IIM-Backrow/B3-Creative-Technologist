#ifndef MOTION_DETECTOR_H
#define MOTION_DETECTOR_H

#include <Arduino.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

// MPU6050 configuration
extern const int MPU_SDA_PIN;
extern const int MPU_SCL_PIN;
extern const float SHAKE_THRESHOLD;
extern const unsigned long SHAKE_DEBOUNCE_TIME;

// MPU6050 sensor object
extern Adafruit_MPU6050 mpu;

// Motion detection variables
extern float lastAccelMagnitude;
extern unsigned long lastShakeTime;

// Function declarations
void initMotionDetector();
void updateMotionDetection();
float calculateAccelMagnitude(sensors_event_t& accel);
void onShake();

#endif