#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec4 aColor;
layout (location = 2) in vec2 aTexCoord;

out vec4 ourColor;
out vec2 TexCoord;

// Controls the scale of the vertices
uniform float scale;

// Uniforms for transformation matrices
uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

void main() {
    // Apply the transformations
    gl_Position = proj * view * model * vec4(aPos.x + aPos.x * scale, aPos.y + aPos.y * scale, aPos.z + aPos.z * scale, 1.0);
    ourColor = aColor;
    TexCoord = aTexCoord;
}

