#ifndef TRIANGLEMESH_H
#define TRIANGLEMESH_H

#include <vector>

#include "Debug.h"

#include "ShaderProgram.h"
#include "VBO.h"
#include "EBO.h"
#include "VAO.h"

#include "Vertex.h"
#include "Texture.h"

namespace Engine {
    class Mesh {
        private:
            VAO vao;
            VBO vbo;
            EBO ebo;
            size_t drawAmount;

            float rotation;
            float scale;

            glm::mat4 model, view, proj;
        public :
            Mesh(GLfloat *vertices, size_t vertAmount, GLuint *indices, size_t indAmount);
            Mesh(const std::vector<Vertex>& vertices, const std::vector<GLuint>& indices);
            ~Mesh();
        
        private:
            void initialize(GLfloat* vertices, size_t vertSize, GLuint* indices, size_t indSize, size_t stride);

        public:
            void update(float deltaTime);
            void draw(std::shared_ptr<ShaderProgram> shader, std::shared_ptr<Texture> texture);
    };
}

#endif // TRIANGLEMESH_H
