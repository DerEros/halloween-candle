#ifndef __ABSTRACT_FRAME_ANIMATION_H__
#define __ABSTRACT_FRAME_ANIMATION_H__

#include "IAnimation.h"

class AbstractFrameAnimation : public IAnimation {
    public:
        AbstractFrameAnimation(Fps fps) {
            _timePerFrameMillis = 1000 / fps;
        }

        virtual void animate(Millis elapseMillis);

    private:
        Millis _timePerFrameMillis;
        Millis _timeSinceFrameSwitchMillis;

        virtual void handleFrameSwitch() = 0;
};

#endif
