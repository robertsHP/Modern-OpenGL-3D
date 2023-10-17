#include "ShaderProgram.h"

namespace Engine {
    ShaderProgram::ShaderProgram(const std::string name) {
        this->name = name;

        std::string vShaderCode, fShaderCode;
        GLuint vSh, fSh;

        vShaderCode = this->loadFile(name+".vert");
        vSh = this->createShader(0, GL_VERTEX_SHADER, (GLchar*) vShaderCode.c_str());
        this->errorCheck(vSh, GL_COMPILE_STATUS, "Vertex shader compilation failed");

        fShaderCode = this->loadFile(name+".frag");
        fSh = this->createShader(1, GL_FRAGMENT_SHADER, (GLchar*) fShaderCode.c_str());
        this->errorCheck(fSh, GL_COMPILE_STATUS, "Fragment shader compilation failed");

        this->id = glCreateProgram();
        glAttachShader(this->id, vSh);
        glAttachShader(this->id, fSh);

        glBindAttribLocation(this->id, 0, "aPos");
        glBindAttribLocation(this->id, 1, "aColor");
        glBindAttribLocation(this->id, 2, "aTexCoord");

        glLinkProgram(this->id);
        this->errorCheck(this->id, GL_LINK_STATUS, "Shader program linking failed");
        glValidateProgram(this->id);
        this->errorCheck(this->id, GL_VALIDATE_STATUS, "Shader program validation failed");

        glDeleteShader(vSh);
        glDeleteShader(fSh);
    }

    ShaderProgram::~ShaderProgram() {
        glDeleteProgram(this->id);
    }

    std::string ShaderProgram::loadFile (const std::string name) {
        std::string code;
        std::ifstream file;
        std::stringstream fileStream;

        // ensures ifstream objects can throw exceptions:
        file.exceptions (std::ifstream::badbit);
        try {
            file.open("shaders/"+name);
            // Read file's buffer contents into streams
            fileStream << file.rdbuf();
            file.close();
            // Convert stream into string
            code = fileStream.str();
        } catch (std::ifstream::failure e) {
            Debug::log("ERROR", "Shader file not successfully read: "+name);
        }
        return code;
    }
    GLuint ShaderProgram::createShader (size_t index, GLenum type, const GLchar *code) {
        GLuint shID = glCreateShader(type);
        glShaderSource(shID, 1, &code, NULL);
        glCompileShader(shID);
        return shID;
    }
    void ShaderProgram::errorCheck (const GLuint objID, GLenum status, const std::string message) {
        GLint success;
        GLchar infoLog[512];

        glGetShaderiv(objID, status, &success);
        if(!success) {
            glGetShaderInfoLog(objID, 512, NULL, infoLog);
            Debug::log("ERROR", message + " : \n" + infoLog);
        }
    }
    void ShaderProgram::activate () {
        glUseProgram(this->id);
    }
    void ShaderProgram::deactivate () {
        glUseProgram(0);
    }
    void ShaderProgram::setBool(const std::string &name, bool value) const {
        glUniform1i(glGetUniformLocation(this->id, name.c_str()), (int)value);
    }
    void ShaderProgram::setInt(const std::string &name, int value) const {
        glUniform1i(glGetUniformLocation(this->id, name.c_str()), value);
    }
    void ShaderProgram::setFloat(const std::string &name, float value) const {
        glUniform1f(glGetUniformLocation(this->id, name.c_str()), value);
    }
    void ShaderProgram::setMat4 (const std::string &name, glm::mat4 value) const {
        int loc = glGetUniformLocation(this->id, name.c_str());
        glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(value));
    }
//    void ShaderProgram::setVec2(const std::string &name, glm::vec2 value) const {
//        glUniform1f(glGetUniformLocation(this->id, name.c_str()), value);
//    }
//    void ShaderProgram::setVec3(const std::string &name, glm::vec3 value) const {
//        glUniform1f(glGetUniformLocation(this->id, name.c_str()), value);
//    }
//    void ShaderProgram::setVec4(const std::string &name, glm::vec4 value) const {
//        glUniform1f(glGetUniformLocation(this->id, name.c_str()), value);
//    }
}
