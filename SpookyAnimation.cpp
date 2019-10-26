#include "SpookyAnimation.h"

#include <FastLED.h>

void SpookyAnimation::handleFrameSwitch() {
    if (on) {
        fill_solid(_pixels, _numPixels, CRGB::Green);
    } else {
        fill_solid(_pixels, _numPixels, CRGB::Black);
    }

    on = !on;
    FastLED.show();
}
