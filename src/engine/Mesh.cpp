#include "Mesh.h"
#include "Engine.h"

namespace Engine {
    // Constructor using raw pointers
    Mesh::Mesh(GLfloat *vertices, size_t vertAmount, GLuint *indices, size_t indAmount) {
        // Assuming each vertex has 8 float components (position, normal, texCoords)
        size_t stride = 8 * sizeof(float);
        
        this->initialize(vertices, vertAmount * sizeof(GLfloat), indices, indAmount * sizeof(GLuint), stride);
    }

    // Constructor using vector of Vertex structs
    Mesh::Mesh(const std::vector<Vertex>& vertices, const std::vector<GLuint>& indices) {
        // Assuming Vertex struct size matches the data layout
        size_t stride = sizeof(Vertex);

        this->initialize(reinterpret_cast<GLfloat*>(const_cast<Vertex*>(vertices.data())), 
                vertices.size() * sizeof(Vertex),
                const_cast<GLuint*>(indices.data()), 
                indices.size() * sizeof(GLuint),
                stride);
    }

    Mesh::~Mesh() {
        this->vao.free();
        this->vbo.free();
        this->ebo.free();
    }

    void Mesh::initialize(GLfloat* vertices, size_t vertSize, GLuint* indices, size_t indSize, size_t stride) {
        this->drawAmount = indSize;
        this->rotation = 0.0f;
        this->scale = 0.0f;

        this->vao.init();
        this->vao.bind();

        // Initialize VBO and EBO
        this->vbo.init(vertices, vertSize);
        this->ebo.init(indices, indSize);

        // Link vertex attributes
        this->vao.linkAttrib(this->vbo, 0, 3, GL_FLOAT, stride, (void*)0); // Position
        this->vao.linkAttrib(this->vbo, 1, 3, GL_FLOAT, stride, (void*)(3 * sizeof(float))); // Normal
        this->vao.linkAttrib(this->vbo, 2, 2, GL_FLOAT, stride, (void*)(6 * sizeof(float))); // TexCoords

        this->vao.unbind();
        this->vbo.unbind();
        this->ebo.unbind();
    }

    void Mesh::update(float deltaTime) {
        this->rotation += 2.0f;

        model = glm::mat4(1.0f);
        view = glm::mat4(1.0f);
        proj = glm::mat4(1.0f);

        model = glm::rotate(model, glm::radians(this->rotation), glm::vec3(1.0f, 0.5f, 0.2f));
        view = glm::translate(view, glm::vec3(0.0f, 0.0f, -2.0f));
        proj = glm::perspective(
            glm::radians(80.0f),
            (float)(Engine::window->width / Engine::window->height),
            0.01f,
            100.0f
        );
    }

    void Mesh::draw(std::shared_ptr<ShaderProgram> shader, std::shared_ptr<Texture> texture) {
        shader->activate();
        shader->setFloat("scale", scale);
        shader->setMat4("model", model);
        shader->setMat4("view", view);
        shader->setMat4("proj", proj);

        if (texture != nullptr)
            texture->bind();

        this->vao.bind();
        glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(this->drawAmount), GL_UNSIGNED_INT, 0);
        this->vao.unbind();

        if (texture != nullptr)
            texture->unbind();

        shader->deactivate();
    }
}
