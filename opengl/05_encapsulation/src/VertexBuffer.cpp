#include "VertexBuffer.h"
#include "Render.h"
#include <glad/glad.h>

VertexBuffer::VertexBuffer(const void* data, unsigned int size):m_RenderId(0)
{
	GLCall(glGenBuffers(1, &m_RenderId));
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_RenderId));
	GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
}

VertexBuffer::~VertexBuffer()
{
	GLCall(glDeleteBuffers(1, &m_RenderId));
}

void VertexBuffer::Bind() const
{
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_RenderId));
}

void VertexBuffer::unBind() const
{
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}
