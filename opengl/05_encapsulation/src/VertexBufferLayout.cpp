#include "VertexBufferLayout.h"

VertexBufferLayout::VertexBufferLayout()
{
	stride = 0;
}

VertexBufferLayout::~VertexBufferLayout()
{
	this->elements.clear();
}
