#include "VertexArrayBuffer.h"
#include "Render.h"
#include <glad/glad.h>

VertexArrayBuffer::VertexArrayBuffer()
{
	GLCall(glGenVertexArrays(1, &m_RenderId));

}

VertexArrayBuffer::~VertexArrayBuffer()
{
	GLCall(glDeleteVertexArrays(1, &m_RenderId));
}

void VertexArrayBuffer::Bind() const
{
	GLCall(glBindVertexArray(m_RenderId));
}

void VertexArrayBuffer::Unbind() const
{
	GLCall(glBindVertexArray(0));
}

/**
 * 根据layout来添加此 vertexArray对应的buffer以及布局
 */
void VertexArrayBuffer::AddBuffer(VertexBuffer& buffer, VertexBufferLayout& layout)
{
	Bind();
	buffer.Bind();
	const auto& eles = layout.GetElements();
	unsigned int offset = 0;
	for (int i = 0; i < eles.size(); i++)
	{
		const auto& ele = eles[i];
		GLCall(glVertexAttribPointer(i, ele.count, ele.type, ele.normalized, layout.GetStride(), (const void*)offset));
		GLCall(glEnableVertexAttribArray(i));
		offset += ele.count * VertexArrayElement::GetSizeOfType(ele.type);
	}
}
