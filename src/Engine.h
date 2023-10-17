#ifndef ENGINE_H
#define ENGINE_H

#include "Debug.h"
#include "Window.h"

namespace Engine {
    extern bool     isLooping;
    extern int      fps;
    extern std::unique_ptr<Window> window;

    void start ();
    void loop ();
    void printOpenGLVersionInfo ();
};

#endif // ENGINE_H
