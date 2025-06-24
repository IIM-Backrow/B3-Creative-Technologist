#ifndef SERVO_CONTROLLER_H
#define SERVO_CONTROLLER_H

#include <Arduino.h>
#include "s3servo.h"
#include "../config/pin_config.h"

extern s3servo myServo;

void initServo();
void openVault();
void closeVault();

#endif