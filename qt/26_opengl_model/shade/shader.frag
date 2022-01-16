#version 330 core
out vec4 FragColor;
in vec2 TexCoord;

uniform sampler2D textureWall;
uniform sampler2D textureFace;
uniform float sample;

void main(){
        FragColor = mix(texture(textureWall, TexCoord),texture(textureFace, TexCoord), sample);
}
