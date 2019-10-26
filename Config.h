#ifndef __CONFIG_H__
#define __CONFIG_H__

#include "global.h"

struct Config {
    float spookProbability;
    Millis spookLength;

    Millis megaSpookWaitTime;
    Millis megaSpookLength;

    Config() {
        spookProbability = 0.001;
        spookLength = 500;

        megaSpookWaitTime = 3600L * 1000L;
        megaSpookLength = 2000;
    }
};

#endif
