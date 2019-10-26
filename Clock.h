#ifndef __CLOCK_H__
#define __CLOCK_H__

#include "global.h"

class Clock {
    public:
        Clock();

        void reset();
        Millis startLap();
        Millis getLastLapTime();
        Millis getTimeSinceStart();

    private:
        Millis _startTime;
        Millis _lapStartTime;
        Millis _lastLapTime;
};

#endif
