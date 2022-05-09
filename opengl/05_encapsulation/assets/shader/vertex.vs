#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec2 texCoord;

out vec2 textureCoords;
uniform mat4 u_MVP;

void main() {
	gl_Position = u_MVP * vec4(aPos.x, aPos.y, aPos.z, 1.0);
	textureCoords = texCoord;
}