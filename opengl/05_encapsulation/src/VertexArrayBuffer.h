#pragma once

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

class VertexArrayBuffer
{
private:
	unsigned int m_RenderId;

public:

	VertexArrayBuffer();
	~VertexArrayBuffer();

	void Bind() const;
	void Unbind() const;

	void AddBuffer(VertexBuffer& buffer, VertexBufferLayout& layout);
};
