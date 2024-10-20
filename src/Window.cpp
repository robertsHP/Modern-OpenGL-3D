#include "Window.h"

namespace Engine {
    Window::Window(std::string name, int width, int height) {
        Debug::log("INFO", "Opening window.");

        this->width = width;
        this->height = height;

        if(!this->initSDL()) {
            return;
        }
        if(!this->loadWindow(name, width, height)) {
            Debug::log("ERROR", "Failed to initialize window data.");
            return;
        }
        if(!this->loadOpenGL(width, height)) {
            Debug::log("ERROR", "Failed to initialize the OpenGL context.");
            return;
        }
    }
    Window::~Window() {
        Debug::log("INFO", "Closing window.");
        if(this->openGLContext) 
            SDL_GL_DeleteContext(this->openGLContext);
        if(this->winPtr) 
            SDL_DestroyWindow(this->winPtr);

        SDL_QuitSubSystem(SDL_INIT_EVERYTHING);
        IMG_Quit();
        SDL_Quit();
    }
    bool Window::initSDL () {
        if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
            std::string errMessage = SDL_GetError();
            Debug::log("ERROR", "SDL2 Could not initialize! SDL_Error: "+errMessage);
            return false;
        }

        if(IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG) {
            std::string errMessage = IMG_GetError();
            Debug::log("ERROR", "SDL_image Could not initialize! IMG_Error: "+errMessage);
            return false;
        }
        return true;
    }
    bool Window::loadWindow (std::string name, int width, int height) {
        this->winPtr = SDL_CreateWindow(
            name.c_str(),
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            width,
            height,
            SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL
        );
        return this->winPtr;
    }
    bool Window::loadOpenGL (int width, int height) {
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_COMPATIBILITY);

        //V-Sync
        SDL_GL_SetSwapInterval(1);

        // SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
        // SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
        // SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
        // SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
        SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

        this->openGLContext = SDL_GL_CreateContext(this->winPtr);

        if (!this->openGLContext) {
            std::string errMessage = SDL_GetError();
            Debug::log("ERROR", "Failed to create OpenGL context: " + errMessage);
            return false;
        }

        if (!gladLoadGL()) {
            this->hasOpenGLContext = false;
            return false;
        }

        this->hasOpenGLContext = true;

        glViewport(0, 0, width, height);
        glEnable(GL_DEPTH_TEST);

        return true;
    }
    void Window::clear () {
        SDL_GL_MakeCurrent(this->winPtr, this->openGLContext);
        glClearColor(0.1f, 0.6f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
    void Window::refreshInput () {
        this->input.update();
    }
    void Window::swapBuffers () {
        SDL_GL_SwapWindow(this->winPtr);
    }
}
