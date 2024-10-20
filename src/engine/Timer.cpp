#include "Timer.h"

namespace Engine {
    bool Timer::check (unsigned miliseconds) {
        bool retVal = false;
        if(this->end - this->start >= miliseconds) {
            this->start = SDL_GetTicks();
            retVal = true;
        }
        this->end = SDL_GetTicks();
        return retVal;
    }
    void Timer::reset () {
        this->start = SDL_GetTicks();
        this->end = SDL_GetTicks();
    }
}
