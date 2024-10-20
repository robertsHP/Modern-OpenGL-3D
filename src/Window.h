#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>

#ifdef _WIN32
    #include <windef.h>
#elif __linux__
    #include <stdint.h>
#elif __APPLE__
    #include <stdint.h>
#endif

#include "SDL.h"
#include "glad/glad.h"
#include "GL/glu.h"
#include "SDL_opengl.h"
#include "SDL_image.h"

#include "Debug.h"
#include "Input.h"

namespace Engine {
    class Window {
        public :
            int width, height;
            bool focused; //implement!!!

            bool hasOpenGLContext = false;
        private:
            SDL_Window   *winPtr;
            SDL_GLContext openGLContext;

            Input input;
        public:
            Window(std::string name, int width, int height);
            virtual ~Window();
        private :
            bool initSDL ();
            bool loadWindow (std::string name, int width, int height);
            bool loadOpenGL (int width, int height);
        public :
            void clear ();
            void refreshInput ();
            void swapBuffers ();
    };
}

#endif // WINDOW_H
