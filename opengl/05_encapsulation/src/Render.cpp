#include "Render.h"
#include <glad/glad.h>
#include <iostream>

void GLClearError()
{
	while (glGetError() != GL_NO_ERROR);
}

// 有异常,则返回false
bool GLLogCall(const char* function, const char* file, const int line)
{
	while (GLenum error = glGetError())
	{
		std::cout << "[OpenGl error] ( 0x" << std::hex << error << " ). " << function << " " << file << ":" << std::dec << line << std::endl;
		return false;
	}

	return true;
}