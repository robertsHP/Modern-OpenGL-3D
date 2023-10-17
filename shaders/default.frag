#version 330 core

// Outputs colors in RGBA
out vec4 FragColor;


// Inputs the color from the Vertex Shader
in vec3 color;
// Inputs the texture coordinates from the Vertex Shader
in vec2 texCoord;

// Gets the Texture Unit from the main function
uniform sampler2D tex0;


void main() {
	vec2 flipped_texcoord = vec2(texCoord.x, 1.0 - texCoord.y);
	FragColor = texture(tex0, flipped_texcoord) * vec4(color, 1.0);
}