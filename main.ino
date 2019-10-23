#include <FastLED.h>

#define LED_PIN 3
#define NUM_PIXELS 3

CRGB pixels[NUM_PIXELS];

void setup() {
    FastLED.addLeds<NEOPIXEL, LED_PIN>(pixels, NUM_PIXELS);
}

void loop() {
    pixels[0] = CRGB::Red;
    FastLED.show();
    delay(500);
    pixels[0] = CRGB::Black;
    FastLED.show();
    delay(500);
}
