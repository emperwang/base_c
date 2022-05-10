#version 330 core
out vec4 FragColor;

in vec2 textureCoords;
in float TexID;

uniform vec4 color;
uniform sampler2D u_textures[2];

void main() {
	// FragColor = color; 
	// int index = int(TexID); // error, don't know reason
	if ( TexID == 0.0f)
	{
		FragColor = texture(u_textures[0], textureCoords);
	}else
	{
		FragColor = texture(u_textures[1], textureCoords);
	}
}