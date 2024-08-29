#ifndef TEXTURE_H
#define TEXTURE_H

#include <memory>
#include "SDL.h"
#include "SDL_image.h"

#include "Global.h"
#include "Debug.h"

#include "ShaderProgram.h"

namespace Engine {
    class Texture {
        public :
            GLuint id;
            int width, height;
            std::string dir;

            GLenum type;
        public :
            Texture (std::string dir, GLenum texType, GLenum slot, GLenum format, GLenum pixelType);
            ~Texture ();

            void texUnit (std::shared_ptr<ShaderProgram> shader, const char* uniform, GLuint unit);
            void bind ();
            void unbind ();
    };
}

#endif // TEXTURE_H
