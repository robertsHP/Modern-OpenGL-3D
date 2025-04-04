#ifndef CAMERA_H
#define CAMERA_H

#include <memory>

#include "Debug.h"
#include "Input.h"
#include "ShaderProgram.h"

namespace Engine {
    class Camera {
        public:
            // Stores the main vectors of the camera
            glm::vec3 position;
            glm::vec3 orientation = glm::vec3(0.0f, 0.0f, -1.0f);
            glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);

            // Prevents the camera from jumping around when first clicking left click
            bool firstClick = true;

            // Stores the width and height of the window
            int width;
            int height;

            // Adjust the speed of the camera and it's sensitivity when looking around
            float speed = 0.1f;
            float sensitivity = 100.0f;

            // Camera constructor to set up initial values
            Camera(int width, int height, glm::vec3 position);

            // Updates and exports the camera matrix to the Vertex Shader
            void matrix(float FOVdeg, float nearPlane, float farPlane, std::unique_ptr<ShaderProgram> &shader, const char* uniform);
            // Handles camera inputs
//            void inputs(GLFWwindow* window);
    };
}

#endif // CAMERA_H
