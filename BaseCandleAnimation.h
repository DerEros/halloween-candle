#ifndef __BASECANDLEANIMATION_H__
#define __BASECANDLEANIMATION_H__

#include <FastLED.h>

#include "AbstractFrameAnimation.h"

class BaseCandleAnimation : public AbstractFrameAnimation {
    public:
        BaseCandleAnimation(CRGB pixels[], unsigned int numPixels, Fps fps) :
            AbstractFrameAnimation(fps), 
            _pixels(pixels), 
            _numPixels(numPixels),
            _paletteIndicies(NULL),
            _flickerRate(20)
        {}

    protected:
        void setPalette(CRGBPalette32 palette);

    private:
        CRGB *_pixels;
        CRGBPalette32 _palette;
        unsigned int _numPixels;
        uint8_t *_paletteIndicies;
        int8_t _flickerRate;

        virtual void handleFrameSwitch();
        void initIndices();
        void flicker();
        void renderPixels();
        
};

#endif /* __BASECANDLEANIMATION_H__ */
