#include "BaseCandleAnimation.h"

void BaseCandleAnimation::handleFrameSwitch() {
    if (_paletteIndicies == NULL) {
        initIndices();
    }

    flicker();
    renderPixels();

    FastLED.show();
}

void BaseCandleAnimation::initIndices() {
    _paletteIndicies = new uint8_t[_numPixels];
    for (unsigned int i = 0; i < _numPixels; i++) {
        _paletteIndicies[i] = random8();
    }
}

void BaseCandleAnimation::setPalette(CRGBPalette32 palette) {
    _palette = palette;
}

void BaseCandleAnimation::flicker() {
    for (unsigned int i = 0; i < _numPixels; i++) {
        int8_t change = random8(_flickerRate);
        change -= _flickerRate / 2;

        _paletteIndicies[i] += change;
    }
}

void BaseCandleAnimation::renderPixels() {
    for (int i = 0; i < _numPixels; i++) {
        _pixels[i] = ColorFromPalette(_palette, _paletteIndicies[i] % 32);
    }
}
