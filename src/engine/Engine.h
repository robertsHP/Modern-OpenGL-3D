#ifndef ENGINE_H
#define ENGINE_H

#include <memory>

#include "Debug.h"
#include "Window.h"
#include "Scene.h"

namespace Engine {
    extern bool                     isLooping;
    extern int                      fps;
    extern std::unique_ptr<Window>  window;
    extern std::unique_ptr<Scene>   scene;

    void init ();
    void setScene (std::unique_ptr<Scene> newScene = nullptr);
    void startLoop ();
    void printOpenGLVersionInfo ();
};

#endif // ENGINE_H
