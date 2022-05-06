#include "IndexBuffer.h"
#include <glad/glad.h>
#include "Render.h"

IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count):m_RenderId(0),m_count(count)
{
	GLCall(glGenBuffers(1, &m_RenderId));
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RenderId));
	GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_count*sizeof(unsigned int), data, GL_STATIC_DRAW));
}

IndexBuffer::~IndexBuffer()
{
	GLCall(glDeleteBuffers(1, &m_RenderId));
}

void IndexBuffer::Bind() const
{
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RenderId));
}

void IndexBuffer::unBind() const
{
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}
