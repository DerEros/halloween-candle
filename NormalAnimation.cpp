#include "NormalAnimation.h"

#include <FastLED.h>


DEFINE_GRADIENT_PALETTE(regularPaletteDef) {
    0,   0,   0,   0,
    138, 255, 0,   0,
    178,  42,  17, 0,
    255, 228, 151, 6
};

CRGBPalette32 _palette = regularPaletteDef;

void NormalAnimation::handleFrameSwitch() {
    if (_paletteIndicies == NULL) {
        initIndices();
    }

    flicker();
    renderPixels();

    FastLED.show();
}

void NormalAnimation::initIndices() {
    _paletteIndicies = new uint8_t[_numPixels];
    for (unsigned int i = 0; i < _numPixels; i++) {
        _paletteIndicies[i] = random8();
    }
}

void NormalAnimation::flicker() {
    for (unsigned int i = 0; i < _numPixels; i++) {
        int8_t change = random8(_flickerRate);
        change -= _flickerRate / 2;

        _paletteIndicies[i] += change;
    }
}

void NormalAnimation::renderPixels() {
    for (int i = 0; i < _numPixels; i++) {
        _pixels[i] = ColorFromPalette(_palette, _paletteIndicies[i]);
    }
}
