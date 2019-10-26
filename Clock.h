#ifndef __CLOCK_H__
#define __CLOCK_H__

#include "global.h"

class Clock {
    public:
        Clock();

        void reset();
        Millis getStartTime();
        Millis startLap();
        Millis getLastLapTime();
        Millis getTimeSinceStart();
        Millis getCurrentTime();

        Millis getTimeSince(Millis sinceTime);

    private:
        Millis _startTime;
        Millis _lapStartTime;
        Millis _lastLapTime;
};

#endif
