#ifndef __SPOOKY_ANIMATION_H__
#define __SPOOKY_ANIMATION_H__

#include <FastLED.h>

#include "AbstractFrameAnimation.h"

class SpookyAnimation : public AbstractFrameAnimation {
    public:
        SpookyAnimation(CRGB pixels[], unsigned int numPixels, Fps fps) :
            AbstractFrameAnimation(fps), _pixels(pixels), _numPixels(numPixels)
        {}

    private:
        CRGB *_pixels;
        unsigned int _numPixels;

        virtual void handleFrameSwitch();
};

#endif
