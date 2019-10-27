#ifndef __SPOOKY_ANIMATION_H__
#define __SPOOKY_ANIMATION_H__

#include <FastLED.h>

#include "BaseCandleAnimation.h"

class SpookyAnimation : public BaseCandleAnimation {
    public:
        SpookyAnimation(CRGB pixels[], unsigned int numPixels, Fps fps); 

    private:
};

#endif
