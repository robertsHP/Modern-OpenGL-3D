#ifndef VERTEX_H
#define VERTEX_H

#include "Includes.h"

namespace Engine {
    struct Vertex {
        glm::vec3 pos;
        glm::vec3 colors;
        glm::vec2 texCoord;
    };
}

#endif // VERTEX_H
