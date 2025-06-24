#ifndef BUTTON_CONTROLLER_H
#define BUTTON_CONTROLLER_H

#include <Arduino.h>

// Button pins
#define BUTTON_PIN_1 1
#define BUTTON_PIN_2 2
#define BUTTON_PIN_3 3
#define BUTTON_PIN_4 8
#define BUTTON_PIN_BACKSPACE 7
#define BUTTON_PIN_CONFIRM 44

void initButtons();
void updateButtons();
void handleButtonPress(int buttonIndex);
void onCodeConfirmed(String code);

#endif