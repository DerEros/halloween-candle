#ifndef __NORMAL_ANIMATION_H__
#define __NORMAL_ANIMATION_H__

#include <FastLED.h>

#include "AbstractFrameAnimation.h"

class NormalAnimation : public AbstractFrameAnimation {
    public:
        NormalAnimation(CRGB pixels[], unsigned int numPixels, Fps fps) :
            AbstractFrameAnimation(fps), _pixels(pixels), _numPixels(numPixels)
        {}

    private:
        CRGB *_pixels;
        unsigned int _numPixels;

        bool on = true;

        virtual void handleFrameSwitch();
};
#endif
