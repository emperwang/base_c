#include "Render.h"
#include <glad/glad.h>
#include <iostream>

#include "VertexArrayBuffer.h"
#include "IndexBuffer.h"
#include "Shader.h"

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

void Renderer::clear() const
{
	GLCall(glClearColor(0.2f, 0.3f, 0.3f, 1.0f));
	GLCall(glClear(GL_COLOR_BUFFER_BIT));
}

void Renderer::clear(const float r, const float g, const float b, const float alpha) const
{
	GLCall(glClearColor(r, g, b, alpha));
	GLCall(glClear(GL_COLOR_BUFFER_BIT));
}

void Renderer::Draw(VertexArrayBuffer& Vao, IndexBuffer& ibuffer, Shader& shader) const
{
	Vao.Bind();
	ibuffer.Bind();
	shader.Bind();
	GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0));
}
