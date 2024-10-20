#ifndef VERTEX_H
#define VERTEX_H

// #include "Includes.h"

#include "glm/glm.hpp"

namespace Engine {
    struct Vertex {
        glm::vec3 position;
        glm::vec3 normal;
        glm::vec2 texCoords;

        Vertex(const glm::vec3& pos, const glm::vec3& norm, const glm::vec2& tex)
            : position(pos), normal(norm), texCoords(tex) {}
    };
}

#endif // VERTEX_H
