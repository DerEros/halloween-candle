#include "AbstractFrameAnimation.h"

void AbstractFrameAnimation::animate(Millis elapsedMillis) {
    this->_timeSinceFrameSwitchMillis += elapsedMillis;

    while (this->_timeSinceFrameSwitchMillis > this->_timePerFrameMillis) {
        this->handleFrameSwitch();
        this->_timeSinceFrameSwitchMillis -= this->_timePerFrameMillis;
    }
}

