#ifndef __NORMAL_ANIMATION_H__
#define __NORMAL_ANIMATION_H__

#include <FastLED.h>

#include "AbstractFrameAnimation.h"

class NormalAnimation : public AbstractFrameAnimation {
    public:
        NormalAnimation(CRGB pixels[], unsigned int numPixels, Fps fps) :
            AbstractFrameAnimation(fps), 
            _pixels(pixels), 
            _numPixels(numPixels),
            _paletteIndicies(NULL),
            _flickerRate(20)
        {}

    private:
        CRGB *_pixels;
        unsigned int _numPixels;
        uint8_t *_paletteIndicies;
        int8_t _flickerRate;

        virtual void handleFrameSwitch();
        void initIndices();
        void flicker();
        void renderPixels();
};
#endif
