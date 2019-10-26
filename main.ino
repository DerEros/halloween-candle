#include <FastLED.h>

#include "global.h"
#include "Config.h"
#include "CandleState.h"
#include "NormalAnimation.h"
#include "SpookyAnimation.h"

#define LED_PIN 3
#define NUM_PIXELS 3
#define ANIMATION_FPS 10

Clock clock;
Config config;
CandleState state(config, clock);

CRGB pixels[NUM_PIXELS];
NormalAnimation normalAnimation(pixels, NUM_PIXELS, ANIMATION_FPS);
SpookyAnimation spookyAnimation(pixels, NUM_PIXELS, ANIMATION_FPS);

void setup() {
    FastLED.addLeds<NEOPIXEL, LED_PIN>(pixels, NUM_PIXELS);
    clock.reset();
}

void loop() {
    clock.startLap();
    normalAnimation.animate(clock.getLastLapTime());

    delay(10);
}
