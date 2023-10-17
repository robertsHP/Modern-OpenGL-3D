#ifndef TEXTURECONTAINER_H
#define TEXTURECONTAINER_H

#include "Debug.h"
#include "Texture.h"

namespace Engine {
    class TextureContainer {
        public :
            std::vector<std::shared_ptr<Texture>> cont;
        public :
            void pushBack (std::shared_ptr<Texture> texture);
            std::shared_ptr<Texture> get (GLuint id);
            bool contains (GLuint id);
    };
}

#endif // TEXTURECONTAINER_H
