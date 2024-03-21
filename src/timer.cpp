#include "timer.hpp"

Timer::Timer() {
    running = false;
    setDelay(200);
    startTime = new std::chrono::time_point<std::chrono::steady_clock>;
}

Timer::~Timer() {
    delete startTime;
}

void Timer::start() {
    *startTime = std::chrono::steady_clock::now();
    running = true;
}

void Timer::stop() {
    endTime = std::chrono::steady_clock::now();
    running = false;
}

bool Timer::hasTimeElapsed() const {
    std::chrono::time_point<std::chrono::steady_clock> currentTime;
    currentTime = std::chrono::steady_clock::now();

    if (!running) {
        return false;
    }

    if ((std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - *startTime)) > dDelay) {
        *startTime = std::chrono::steady_clock::now();
        return true;
    }

    else return false;
}

void Timer::setDelay(int input) {

    if (input < 1) {
        input = 1;
    }

    iDelay = input;

    std::chrono::duration<int, std::milli> temp(input);
    dDelay = temp;
}

int Timer::getDelay() const {
    return iDelay;
}

bool Timer::isRunning() const {
    return running;
}

void Timer::setRunning(bool input) {
    running = input;
}
