#ifndef BUTTON_CONTROLLER_H
#define BUTTON_CONTROLLER_H

#include <Arduino.h>
#include "../config/pin_config.h"

void initButtons();
void updateButtons();
void handleButtonPress(int buttonIndex);
void onCodeConfirmed(String code);

#endif