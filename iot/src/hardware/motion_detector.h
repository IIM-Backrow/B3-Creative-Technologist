#ifndef MOTION_DETECTOR_H
#define MOTION_DETECTOR_H

#include <Arduino.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include "../config/pin_config.h"

// MPU6050 configuration
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