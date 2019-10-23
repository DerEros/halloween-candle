#ifndef __I_ANIMATION_H__
#define __I_ANIMATION_H__

#include "global.h"

class IAnimation {
    public:
        virtual void animate(Millis elapsedMillis) = 0;
};
#endif
