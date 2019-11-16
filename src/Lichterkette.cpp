//
// Created by marc on 06.11.19.
//

#define MODE_BUTTON_PIN 3

#include "Arduino.h"
#include "FastLED.h"
#include "LightController.h"

#include "Effects/ColorDraw.h"
#include "Effects/RandomColors.h"
#include "Effects/BouncingPixel.h"
#include "Effects/ChristmasPalette.h"

LightController *lc = new LightController();

volatile int effectID = 3;
volatile boolean needsClearingLED = false;

volatile unsigned long lastDebounceTime = 0;  // the last time the mode was toggled
volatile unsigned long debounceDelay = 200;

ColorDraw *cd = new ColorDraw(*lc);
RandomColors *rc = new RandomColors(*lc);
BouncingPixel *bp = new BouncingPixel(*lc);
ChristmasPalette *cp = new ChristmasPalette(*lc);

void modeButtonPressed() {
  if ((millis() - lastDebounceTime) < debounceDelay) {
    Serial.println("DEBOUNCED");
    return;
  }

  lastDebounceTime = millis();

  if(effectID + 1 > 3) {
    effectID = 0;
  } else {
    effectID++;
  }

  needsClearingLED = true;
}

void setup() {
    pinMode(MODE_BUTTON_PIN, OUTPUT);
    digitalWrite(MODE_BUTTON_PIN, HIGH);
    Serial.begin(9600);
    attachInterrupt(digitalPinToInterrupt(MODE_BUTTON_PIN), modeButtonPressed, FALLING);

    randomSeed(analogRead(0));

    lc->blackAllLEDS();

    lc->updateLEDs();
}

void loop() {

  if(needsClearingLED) {
    lc->blackAllLEDS();
    needsClearingLED = false;
  }

  switch (effectID) {
    case 0: cd->Tick(); break;
    case 1: rc->Tick(); break;
    case 2: bp->Tick(); break;
    case 3: cp->Tick(); break;
  }

  delay(100);
}
