#include <FastLED.h>

#include "global.h"
#include "Config.h"
#include "CandleState.h"
#include "NormalAnimation.h"
#include "SpookyAnimation.h"

#define LED_PIN 3
#define NUM_PIXELS 3
#define ANIMATION_FPS 25
#define SPOOKY_ANIMATION_FPS 50

Clock clock;
Config config;
CandleState state(config, clock);
CandleState::State currentState = CandleState::NORMAL;

CRGB pixels[NUM_PIXELS];
NormalAnimation normalAnimation(pixels, NUM_PIXELS, ANIMATION_FPS);
SpookyAnimation spookyAnimation(pixels, NUM_PIXELS, SPOOKY_ANIMATION_FPS);

void setup() {
    FastLED.addLeds<NEOPIXEL, LED_PIN>(pixels, NUM_PIXELS);
    clock.reset();
}

void loop() {
    clock.startLap();

    currentState = state.nextState(currentState);

    switch (currentState) {
        case CandleState::SPOOK:
        case CandleState::MEGA_SPOOK:
            spookyAnimation.animate(clock.getLastLapTime());
            break;
        default:
        case CandleState::NORMAL:
            normalAnimation.animate(clock.getLastLapTime());
            break;
    }

    delay(10);
}
