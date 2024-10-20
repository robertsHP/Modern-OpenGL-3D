#include "Engine.h"

namespace Engine {
    bool    isLooping;
    int     fps = 0;
    std::unique_ptr<Window> window;
    std::unique_ptr<Scene> scene;

    void start () {
        window = std::make_unique<Window>("GFX Engine", 1024, 768);
        if(window) {
            if (window->hasOpenGLContext) {
                Debug::log("ERROR", "BRAWLZZ.");

                printOpenGLVersionInfo();

                Debug::log("ERROR", "AAAAAAAAAAAAAAAAAAAAAAAAA.");

                scene = std::make_unique<Scene>();

                Debug::log("ERROR", "BALLLZZ.");


                loop();
            }
        }
    }
    void loop () {
        const int FRAME_DELAY = 1000 / 60;
        int deltaTime = 0;
        int lastFrame, frameCount = 0, lastTime = 0;

        isLooping = true;
        while(isLooping) {
            lastFrame = SDL_GetTicks();
            if(lastFrame >= (lastTime + 1000)) {
                lastTime = lastFrame;
                fps = frameCount;
                frameCount = 0;
            }

            window->clear();
//                Input::update();
//                StateHandler::updateInformation();
////                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//                win.draw();
            window->refreshInput();

            scene->input();
            scene->update(deltaTime);
            scene->draw();

            window->swapBuffers();
            frameCount++;

            deltaTime = SDL_GetTicks() - lastFrame;
            if(FRAME_DELAY > deltaTime){
                SDL_Delay(FRAME_DELAY - deltaTime);
            }
        }
    }
    void printOpenGLVersionInfo () {
        Debug::print("Vendor: ");
        Debug::println((const char*) glGetString(GL_VENDOR));
        Debug::print("Renderer: ");
        Debug::println((const char*) glGetString(GL_RENDERER));
        Debug::print("Version: ");
        Debug::println((const char*) glGetString(GL_VERSION));
        Debug::print("Shading Language: ");
        Debug::println((const char*) glGetString(GL_SHADING_LANGUAGE_VERSION));
    }
}
