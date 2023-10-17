#ifndef WINDOW_H
#define WINDOW_H

#include "Debug.h"
#include "Input.h"
#include "TextureContainer.h"

#include "ShaderProgram.h"
#include "Texture.h"
#include "Mesh.h"

namespace Engine {
    class Window {
        public :
            int width;
            int height;
        private:
            SDL_Window   *winPtr;
            SDL_GLContext openGLContext;

            Input input;
            TextureContainer txtrCont;

            std::shared_ptr<ShaderProgram> plainShader;
            std::shared_ptr<Mesh> square;
            std::shared_ptr<Texture> texture;
        public:
            Window(std::string name, int width, int height);
            virtual ~Window();
        private :
            bool initSDL ();
            bool loadWindow (std::string name, int width, int height);
            bool loadOpenGL (int width, int height);
        public :
            void clear ();
            void update (float deltaTime);
            void draw ();
            void swapBuffers ();
    };
}

#endif // WINDOW_H
