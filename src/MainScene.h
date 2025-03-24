#pragma once

#include "engine/Engine.h"
#include "engine/Debug.h"
#include "engine/Input.h"

#include "engine/ShaderProgram.h"
#include "engine/Texture.h"
#include "engine/Mesh.h"
#include "engine/Vertex.h"

class MainScene : public Engine::Scene {
    private :
        std::shared_ptr<Engine::ShaderProgram> plainShader;
        std::shared_ptr<Engine::Mesh> mesh;
        std::shared_ptr<Engine::Texture> texture;
    public:
        MainScene();
        ~MainScene();

        void input () override;
        void update (float deltaTime) override;
        void draw () override;
};

