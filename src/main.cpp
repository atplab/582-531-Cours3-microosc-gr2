#include <Arduino.h>
#include <MicroOscSlip.h>
#include <FastLED.h>

#define MA_BROCHE_BOUTON 39
#define MA_BROCHE_ANGLE 32

MicroOscSlip<128> monOsc(&Serial);

CRGB monPixel;


void setup() {
  pinMode( MA_BROCHE_BOUTON , INPUT );
  Serial.begin(115200);
  FastLED.addLeds<WS2812, 27, GRB>(&monPixel, 1);
}

void loop() {

  int maLectureBouton = digitalRead( MA_BROCHE_BOUTON );
  int maLectureAnalogique = analogRead(MA_BROCHE_ANGLE);
  monOsc.sendInt( "/bouton" , maLectureBouton );
  monOsc.sendInt("/angle", maLectureAnalogique);

  monPixel = CRGB(0, millis() % 255, 0);
  FastLED.show();
  delay(100);
}


