#include "NormalAnimation.h"

DEFINE_GRADIENT_PALETTE(paletteDef) {
    0,   0,   0,   0,
    138, 220,  30, 0,
    178,  42,  17, 0,
    255, 228, 151, 0
};

NormalAnimation::NormalAnimation(CRGB pixels[], unsigned int numPixels, Fps fps) :
    BaseCandleAnimation(pixels, numPixels, fps) {

    setPalette(paletteDef);
}
