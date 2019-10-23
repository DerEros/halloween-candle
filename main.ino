#include <FastLED.h>

#include "global.h"
#include "NormalAnimation.h"

#define LED_PIN 3
#define NUM_PIXELS 3

CRGB pixels[NUM_PIXELS];
NormalAnimation normalAnimation(pixels, NUM_PIXELS);

Millis lastMillis;

void setup() {
    FastLED.addLeds<NEOPIXEL, LED_PIN>(pixels, NUM_PIXELS);
    lastMillis = millis();
}

void loop() {
    Millis currentTime = millis();
    normalAnimation.animate(currentTime - lastMillis);

    lastMillis = currentTime;
    delay(10);
}
