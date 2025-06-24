#include "button_controller.h"
#include "../config/vault_config.h"
#include "servo_controller.h"
#include "led_controller.h"

// Variables pour gérer l'état des boutons
bool lastButtonState[6] = {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH};
bool currentButtonState[6] = {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH};
unsigned long lastDebounceTime[6] = {0, 0, 0, 0, 0, 0};
unsigned long debounceDelay = 50;

// Variable pour stocker le code entré
String currentCode = "";

// Pins des boutons dans l'ordre
int buttonPins[6] = {BUTTON_PIN_1, BUTTON_PIN_2, BUTTON_PIN_3, BUTTON_PIN_4, BUTTON_PIN_BACKSPACE, BUTTON_PIN_CONFIRM};

void initButtons() {
  pinMode(BUTTON_PIN_1, INPUT_PULLUP);
  pinMode(BUTTON_PIN_2, INPUT_PULLUP);
  pinMode(BUTTON_PIN_3, INPUT_PULLUP);
  pinMode(BUTTON_PIN_4, INPUT_PULLUP);
  pinMode(BUTTON_PIN_BACKSPACE, INPUT_PULLUP);
  pinMode(BUTTON_PIN_CONFIRM, INPUT_PULLUP);
}

void updateButtons() {
  for (int i = 0; i < 6; i++) {
    int reading = digitalRead(buttonPins[i]);

    if (reading != lastButtonState[i]) {
      lastDebounceTime[i] = millis();
    }

    if ((millis() - lastDebounceTime[i]) > debounceDelay) {
      if (reading != currentButtonState[i]) {
        currentButtonState[i] = reading;

        if (currentButtonState[i] == LOW) {
          handleButtonPress(i);
        }
      }
    }

    lastButtonState[i] = reading;
  }
}

void handleButtonPress(int buttonIndex) {
  switch (buttonIndex) {
    case 0: // BUTTON_PIN_1
      currentCode += "1";
      Serial.print("Button 1 pressed: ");
      Serial.println(currentCode);
      break;

    case 1: // BUTTON_PIN_2
      currentCode += "2";
      Serial.print("Button 2 pressed: ");
      Serial.println(currentCode);
      break;

    case 2: // BUTTON_PIN_3
      currentCode += "3";
      Serial.print("Button 3 pressed: ");
      Serial.println(currentCode);
      break;

    case 3: // BUTTON_PIN_4
      currentCode += "4";
      Serial.print("Button 4 pressed: ");
      Serial.println(currentCode);
      break;

    case 4: // BUTTON_PIN_BACKSPACE
      if (currentCode.length() > 0) {
        currentCode.remove(currentCode.length() - 1);
      }
      Serial.print("Button backspace pressed: ");
      Serial.println(currentCode);
      break;

    case 5: // BUTTON_PIN_CONFIRM
      if (currentCode.length() > 0) {
        Serial.print("Button confirm pressed: ");
        Serial.println(currentCode);
        onCodeConfirmed(currentCode);
        currentCode = "";
      }
      break;
  }
}

void onCodeConfirmed(String code) {
  if (code == SECRET_CODE) {
    if (!vaultOpen) {
      openVault();
      vaultOpen = true;
      setLight(COLOR_GREEN);
    } else {
      closeVault();
      vaultOpen = false;
      setLight(COLOR_OFF);
    }
  } else {
    setLight(COLOR_RED);
    delay(1000);
    setLight(COLOR_OFF);
  }
}
