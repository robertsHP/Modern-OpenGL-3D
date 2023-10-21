#include "Scene.h"

#include "Input.h"

namespace Engine {
    Scene::Scene() {
        Debug::log("INFO", "Loading scene.");

        this->plainShader = std::make_shared<ShaderProgram>("default");

        this->texture = std::make_shared<Texture>(
            "gfx/btest.png",
            GL_TEXTURE_2D,
            GL_TEXTURE0,
            GL_RGBA,
            GL_UNSIGNED_BYTE);
        this->texture->texUnit(this->plainShader, "tex0", 0);

//        Vertex vertices [] = {
//            Vertex(glm::vec3(-0.5f, 0.0f,  0.5f), glm::vec3(1.0f, 1.0f, 1.0f)), glm::vec2(0.0f, 0.0f)),
//            Vertex(glm::vec3(-0.5f, 0.0f, -0.5f), glm::vec3(1.0f, 1.0f, 1.0f)), glm::vec2(5.0f, 0.0f)),
//            Vertex(glm::vec3(0.5f, 0.0f, -0.5f), glm::vec3(1.0f, 1.0f, 1.0f)), glm::vec2(0.0f, 0.0f)),
//            Vertex(glm::vec3(0.5f, 0.0f,  0.5f), glm::vec3(1.0f, 1.0f, 1.0f)), glm::vec2(5.0f, 0.0f)),
//            Vertex(glm::vec3(0.0f, 0.8f,  0.0f), glm::vec3(1.0f, 1.0f, 1.0f)), glm::vec2(2.5f, 5.0f)),
//        };

        // Vertices coordinates
        GLfloat vertices[] =
        { //     COORDINATES     /        COLORS      /   TexCoord  //
            -0.5f, 0.0f,  0.5f,     1.0f, 1.0f, 1.0f,	0.0f, 0.0f,
            -0.5f, 0.0f, -0.5f,     1.0f, 1.0f, 1.0f,	5.0f, 0.0f,
             0.5f, 0.0f, -0.5f,     1.0f, 1.0f, 1.0f,	0.0f, 0.0f,
             0.5f, 0.0f,  0.5f,     1.0f, 1.0f, 1.0f,	5.0f, 0.0f,
             0.0f, 0.8f,  0.0f,     1.0f, 1.0f, 1.0f,	2.5f, 5.0f
        };

        // Indices for vertices order
        GLuint indices[] =
        {
            0, 1, 2,
            0, 2, 3,
            0, 1, 4,
            1, 2, 4,
            2, 3, 4,
            3, 0, 4
        };

        this->square = std::make_shared<Mesh>(
            vertices, sizeof(vertices),
            indices, sizeof(indices)
        );
    }
    Scene::~Scene() {
        Debug::log("INFO", "Closing scene.");
    }
    void Scene::input () {

    }
    void Scene::update (float deltaTime) {
        this->square->update(deltaTime);
    }
    void Scene::draw () {
        this->square->draw(this->plainShader, this->texture);
    }
}
