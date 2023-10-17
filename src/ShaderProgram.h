#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

#include "Includes.h"
#include "Debug.h"

namespace Engine {
    class ShaderProgram {
        public :
            GLuint id;
            std::string name;
        public :
            ShaderProgram(const std::string name);
            ~ShaderProgram();
        private :
            std::string loadFile (const std::string name);
            GLuint createShader (size_t index, GLenum type, const GLchar *code);
            void errorCheck (const GLuint objID, GLenum status, const std::string message);
        public :
            void activate ();
            void deactivate ();
            void setBool(const std::string &name, bool value) const;
            void setInt(const std::string &name, int value) const;
            void setFloat(const std::string &name, float value) const;
            void setMat4 (const std::string &name, glm::mat4 value) const;
//            void setVec2(const std::string &name, glm::vec2 value) const;
//            void setVec3(const std::string &name, glm::vec3 value) const;
//            void setVec4(const std::string &name, glm::vec4 value) const;
    };
}

#endif // SHADERPROGRAM_H
