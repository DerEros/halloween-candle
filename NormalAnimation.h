#ifndef __NORMAL_ANIMATION_H__
#define __NORMAL_ANIMATION_H__

#include <FastLED.h>

#include "BaseCandleAnimation.h"

class NormalAnimation : public BaseCandleAnimation {
    public:
        NormalAnimation(CRGB pixels[], unsigned int numPixels, Fps fps); 

    private:
};
#endif
