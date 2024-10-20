#include "EBO.h"

namespace Engine {
    void EBO::init (GLuint *indices, GLsizeiptr size) {
        glGenBuffers(1, &this->id);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->id);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
    }
    void EBO::bind () {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->id);
    }
    void EBO::unbind () {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }
    void EBO::free () {
        glDeleteBuffers(1, &this->id);
    }
}
