#ifndef VBO_H
#define VBO_H

#include "glad/glad.h"

namespace Engine {
    class VBO {
        public :
            GLuint id;
        public :
            void init (GLfloat *vertices, GLsizeiptr size);
            void bind ();
            void unbind ();
            void free ();
    };
}

#endif // VBO_H
