#ifndef TRIANGLEMESH_H
#define TRIANGLEMESH_H

#include "Debug.h"

#include "ShaderProgram.h"
#include "VBO.h"
#include "EBO.h"
#include "VAO.h"
#include "Texture.h"

namespace Engine {
    class Mesh {
        public :
            VAO vao;
            VBO vbo;
            EBO ebo;

            size_t drawAmount;
            float rotation;
            float scale;

            glm::mat4 model;
            glm::mat4 view;
            glm::mat4 proj;
        public :
            Mesh(GLfloat *vertices, size_t vertAmount, GLuint *indices, size_t indAmount);
            ~Mesh();

            void update (float deltaTime);
            void draw (std::shared_ptr<ShaderProgram> shader, std::shared_ptr<Texture> texture = nullptr);
    };
}

#endif // TRIANGLEMESH_H
