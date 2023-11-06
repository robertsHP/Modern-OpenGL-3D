#ifndef TIMER_H
#define TIMER_H

#include "SDL.h"

#include "Global.h"
#include "Debug.h"

namespace Engine {
    class Timer {
        private :
            unsigned start = SDL_GetTicks();
            unsigned end = SDL_GetTicks();
        public :
            bool check (unsigned miliseconds);
            void reset ();
    };
}

#endif // TIMER_H
