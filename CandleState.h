#ifndef __CANDLE_STATE_H__
#define __CANDLE_STATE_H__

#include "Config.h"
#include "Clock.h"

class CandleState {
    public:
        enum State {
            NORMAL,
            SPOOK,
            MEGA_SPOOK
        };
    
        CandleState(Config& config, Clock& clock) : 
            _clock(clock),
            _config(config)
        {}

        State nextState();

    private:
        Clock& _clock;
        Config& _config;
};

#endif
