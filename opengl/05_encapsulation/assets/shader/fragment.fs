#version 330 core
out vec4 FragColor;

in vec2 textureCoords;

uniform vec4 color;
uniform sampler2D tex1;

void main() {
	// FragColor = color; 
	FragColor = texture(tex1, textureCoords);
}