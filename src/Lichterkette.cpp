//
// Created by marc on 06.11.19.
//

#include "Arduino.h"
#include "FastLED.h"
#include "LightController.h"
#include "Effects/BouncingPixel.h"

LightController *lc = new LightController();
BouncingPixel *bp = new BouncingPixel(*lc);

void setup() {
    Serial.begin(9600);

    /*for(int i = 0; i < lc->getLEDCount(); i++) {
      lc->setLEDColor( *new CRGB(255, 0, 0), i, 255);
      Serial.println(i);
    }*/



    lc->updateLEDs();
}

void loop() {
  bp->Tick();
  delay(100);

  /*for(int i = 0; i < lc->getLEDCount(); i++) {
    lc->setLEDColor( *new CRGB(255, 0, 0), i, 255);
    lc->updateLEDs();
    delay(10);
  }

  delay(100);

  for(int i = lc->getLEDCount(); i > 0; i--) {
    lc->setLEDColor( *new CRGB(0, 0, 255), i, 255);
    lc->updateLEDs();
    delay(10);
  }*/
}
