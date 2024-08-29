#include "Mesh.h"
#include "Engine.h"

namespace Engine {
    Mesh::Mesh(GLfloat *vertices, size_t vertAmount, GLuint *indices, size_t indAmount) {
        this->drawAmount = indAmount;
        this->rotation = 0.0f;
        this->scale = 0.0f;

        this->vao.init();
        this->vao.bind();
//            std::vector<Vertex> finalVertices (vertAmount * Vertex.DEFAULT_SIZE);
//
//            for (int i = 0; i < vertAmount; i++) {
//                finalVertices.push_back(vertices[i]);
//            }

            this->vbo.init(vertices, vertAmount);
            this->ebo.init(indices, indAmount);
            this->vao.linkAttrib(this->vbo, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
            this->vao.linkAttrib(this->vbo, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
            this->vao.linkAttrib(this->vbo, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
        this->vao.unbind();
        this->vbo.unbind();
        this->ebo.unbind();
    }
    Mesh::~Mesh() {
        this->vao.free();
        this->vbo.free();
        this->ebo.free();
    }
    void Mesh::update (float deltaTime) {
        this->rotation += 2.0f;

        model = glm::mat4(1.0f);
        view = glm::mat4(1.0f);
        proj = glm::mat4(1.0f);

        model = glm::rotate(model, glm::radians(this->rotation), glm::vec3(1.0f, 0.5f, 0.2f));
        view = glm::translate(view, glm::vec3(0.0f, 0.0f, -2.0f));
        proj = glm::perspective(
            glm::radians(80.0f),
            (float) (Engine::window->width / Engine::window->height),
            0.01f,
            100.0f
        );
    }
    void Mesh::draw (std::shared_ptr<ShaderProgram> shader, std::shared_ptr<Texture> texture) {
        shader->activate();
            shader->setFloat("scale", scale);
            shader->setMat4("model", model);
            shader->setMat4("view", view);
            shader->setMat4("proj", proj);
            if(texture != nullptr)
                texture->bind();
            this->vao.bind();
                glDrawElements(GL_TRIANGLES, this->drawAmount / sizeof(float), GL_UNSIGNED_INT, 0);
            this->vao.unbind();
            if(texture != nullptr)
                texture->unbind();
        shader->deactivate();
    }
}
