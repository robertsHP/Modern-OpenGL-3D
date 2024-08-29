#ifndef SCENE_H
#define SCENE_H

#include "TextureContainer.h"
#include "Debug.h"

#include "ShaderProgram.h"
#include "Texture.h"
#include "Mesh.h"

namespace Engine {
    class Scene {
        public :
            TextureContainer txtrCont;

            std::shared_ptr<ShaderProgram> plainShader;
            std::shared_ptr<Mesh> square;
            std::shared_ptr<Texture> texture;
        public:
            Scene();
            ~Scene();

            void input ();
            void update (float deltaTime);
            void draw ();
    };
}

#endif // SCENE_H
