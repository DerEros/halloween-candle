#include "Clock.h"

#include <Arduino.h>

Clock::Clock() {
    this->reset();
}

void Clock::reset() {
    _startTime = millis();
    _lapStartTime = _startTime;
}

Millis Clock::getStartTime() {
    return _startTime;
}

Millis Clock::startLap() {
    Millis now = millis();

    _lastLapTime = now - _lapStartTime;
    _lapStartTime = now;

    return _lastLapTime;
}

Millis Clock::getLastLapTime() {
    return _lastLapTime;
}

Millis Clock::getTimeSinceStart() {
    return millis() - _startTime;
}

Millis Clock::getCurrentTime() {
    return millis();
}

Millis Clock::getTimeSince(Millis sinceTime) {
    return millis() - sinceTime;
}
