#include "CandleState.h"

#include <FastLED.h>

CandleState::State CandleState::nextState(CandleState::State lastState) {
    switch (lastState) {
        case CandleState::SPOOK:
            return handleSpookState();
        case CandleState::MEGA_SPOOK:
            return handleMegaSpookState();
        case CandleState::NORMAL:
        default:
            return handleNormalState();
    }
}

CandleState::State CandleState::handleNormalState() {
    if (isSpookyTime()) {
        return CandleState::SPOOK;
    } else if (isMegaSpookyTime()) {
        _clock.reset();
        _spookStartTime = _clock.getCurrentTime();
        return CandleState::MEGA_SPOOK;
    } else {
        _spookStartTime = _clock.getCurrentTime();
        return CandleState::NORMAL;
    }
}

CandleState::State CandleState::handleSpookState() {
    if (_clock.getTimeSince(_spookStartTime) < _config.spookLength) {
        return CandleState::SPOOK;
    } else {
        return CandleState::NORMAL;
    }
}

CandleState::State CandleState::handleMegaSpookState() {
    if (_clock.getTimeSince(_spookStartTime) < _config.megaSpookLength) {
        return CandleState::MEGA_SPOOK;
    } else {
        return CandleState::NORMAL;
    }
}

bool CandleState::isSpookyTime() {
    float probabilityByTime = _config.spookProbability * (_clock.getLastLapTime() / 1000.0);
    unsigned int pivotPoint = 65536 * probabilityByTime;
    return random16() < pivotPoint;
}

bool CandleState::isMegaSpookyTime() {
    return (_clock.getTimeSinceStart() > _config.megaSpookWaitTime);
}
