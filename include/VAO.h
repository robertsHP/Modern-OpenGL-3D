#ifndef VAO_H
#define VAO_H

#include "glad/gl.h"
#include "VBO.h"

namespace Engine {
    class VAO {
        public :
            GLuint id;
        public :
            void init ();
            void linkAttrib (VBO &vbo, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void *offset);
            void bind ();
            void unbind ();
            void free ();
    };
}

#endif // VAO_H
