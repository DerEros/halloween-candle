#include "SpookyAnimation.h"

DEFINE_GRADIENT_PALETTE(spookyPaletteDef) {
    0,     0,   0,   0,
    137,   4, 129,   0,
    196,   0,   6,   1,
    255, 162,   3, 224 
};

SpookyAnimation::SpookyAnimation(CRGB pixels[], unsigned int numPixels, Fps fps) :
    BaseCandleAnimation(pixels, numPixels, fps) {

    setPalette(spookyPaletteDef);
}
