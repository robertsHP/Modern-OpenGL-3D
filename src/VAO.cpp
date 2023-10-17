#include "VAO.h"

namespace Engine {
    void VAO::init () {
        glGenVertexArrays(1, &this->id);
    }
    void VAO::linkAttrib (VBO &vbo, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void *offset) {
        vbo.bind();
//            glVertexAttribPointer(layout, 3, GL_FLOAT, GL_FALSE, 0, (void*) 0);
            glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
            glEnableVertexAttribArray(layout);
        vbo.unbind();
    }
    void VAO::bind () {
        glBindVertexArray(this->id);
    }
    void VAO::unbind () {
        glBindVertexArray(0);
    }
    void VAO::free () {
        glDeleteVertexArrays(1, &this->id);
    }
}
