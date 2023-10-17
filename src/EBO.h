#ifndef EBO_H
#define EBO_H

#include "glad/gl.h"

namespace Engine {
    class EBO {
        public :
            GLuint id;
        public :
            void init (GLuint *indices, GLsizeiptr size);
            void bind ();
            void unbind ();
            void free ();
    };
}

#endif // EBO_H
