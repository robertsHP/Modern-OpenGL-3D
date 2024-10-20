#include "Texture.h"

namespace Engine {
    Texture::Texture (std::string dir, GLenum texType, GLenum slot, GLenum format, GLenum pixelType) {
        Debug::log("INFO", "Loading texture "+this->dir);
        this->dir = dir;
        this->type = texType;

        SDL_Surface *surf = IMG_Load(dir.c_str());
        if(surf) {
            this->width = surf->w;
            this->height = surf->h;

            glGenTextures(1, &this->id);
            glActiveTexture(slot);
            glBindTexture(type, this->id);
                // Set our texture parameters
                glTexParameteri(type, GL_TEXTURE_WRAP_S, GL_REPEAT);
                glTexParameteri(type, GL_TEXTURE_WRAP_T, GL_REPEAT);
                // Set texture filtering
                glTexParameteri(type, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
                glTexParameteri(type, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
                // Load, create texture and generate mipmaps
                glTexImage2D(type, 0, GL_RGBA, this->width, this->height, 0, format, pixelType, surf->pixels);
                glad_glGenerateMipmap(type);
            glBindTexture(type, 0);

            SDL_FreeSurface(surf);
        } else {
            Debug::log("ERROR", "Texture "+dir+" failed to load");
        }
    }
    Texture::~Texture () {
        Debug::log("INFO", "Deleting texture "+this->dir);
        glDeleteTextures(1, &this->id);
    }
    void Texture::texUnit (std::shared_ptr<ShaderProgram> shader, const char* uniform, GLuint unit) {
        // Gets the location of the uniform
        GLuint texUni = glGetUniformLocation(shader->id, uniform);
        // Shader needs to be activated before changing the value of a uniform
        shader->activate();
        // Sets the value of the uniform
        glUniform1i(texUni, unit);
    }
    void Texture::bind () {
        glBindTexture(type, this->id);
    }
    void Texture::unbind () {
        glBindTexture(type, 0);
    }
}
