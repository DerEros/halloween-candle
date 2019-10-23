#include "NormalAnimation.h"

#include <FastLED.h>

void NormalAnimation::handleFrameSwitch() {
    if (on) {
        fill_solid(_pixels, _numPixels, CRGB::Red);
    } else {
        fill_solid(_pixels, _numPixels, CRGB::Black);
    }

    on = !on;

    FastLED.show();
}
