#include "Cube.h"

// namespace Engine {
//     Cube::Cube() {
//         // Define the vertices for the cube
//         std::vector<Engine::Vertex> vertices = {
//             Engine::Vertex(glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f)),
//             Engine::Vertex(glm::vec3(0.5f, -0.5f,  0.5f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f)),
//             Engine::Vertex(glm::vec3(0.5f, 0.5f,  0.5f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)),
//             Engine::Vertex(glm::vec3(-0.5f, 0.5f,  0.5f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f)),
//             Engine::Vertex(glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f)),
//             Engine::Vertex(glm::vec3(0.5f, -0.5f, -0.5f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f)),
//             Engine::Vertex(glm::vec3(0.5f, 0.5f, -0.5f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)),
//             Engine::Vertex(glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f)),
//         };

//         // Define the indices for the cube
//         std::vector<GLuint> indices = {
//             0, 1, 2, 2, 3, 0, // Front face
//             1, 5, 6, 6, 2, 1, // Right face
//             5, 4, 7, 7, 6, 5, // Back face
//             4, 0, 3, 3, 7, 4, // Left face
//             4, 5, 1, 1, 0, 4, // Bottom face
//             3, 2, 6, 6, 7, 3, // Top face
//         };

//         // Create the mesh with the vertices and indices
//         mesh = std::make_unique<Engine::Mesh>(vertices, indices);
//     }

//     void Cube::draw(std::shared_ptr<Engine::ShaderProgram> shader) {
//         mesh->draw(shader, this->texture);
//     }
// }