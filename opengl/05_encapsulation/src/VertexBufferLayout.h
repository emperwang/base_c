#pragma once
#include <glad/glad.h>
#include <vector>

struct VertexArrayElement 
{
	unsigned int type;
	unsigned int count;
	unsigned char normalized;

	static unsigned int GetSizeOfType(unsigned int type)
	{
		switch (type)
		{
		case GL_FLOAT:			return 4;
		case GL_UNSIGNED_INT:	return 4;
		case GL_UNSIGNED_BYTE:	return 1;
		}
		return 0;
	}
};

class VertexBufferLayout
{
private:
	std::vector<VertexArrayElement> elements;
	unsigned int stride;
public:

	VertexBufferLayout();
	~VertexBufferLayout();


	inline std::vector<VertexArrayElement> GetElements() const
	{
		return this->elements;
	}

	template <typename T>
	void Push(unsigned int count)
	{

	}

	template <>
	void Push<float>(unsigned int count)
	{
		this->elements.push_back({ GL_FLOAT, count, GL_FALSE });
		stride += count * VertexArrayElement::GetSizeOfType(GL_FLOAT);
	}


	template <>
	void Push<unsigned int>(unsigned int count)
	{
		this->elements.push_back({ GL_UNSIGNED_INT, count, GL_FALSE });
		stride += count * VertexArrayElement::GetSizeOfType(GL_UNSIGNED_INT);
	}

	template <>
	void Push<unsigned char>(unsigned int count)
	{
		this->elements.push_back({ GL_UNSIGNED_BYTE, count, GL_TRUE });
		stride += count * VertexArrayElement::GetSizeOfType(GL_UNSIGNED_BYTE);
	}
	inline unsigned int GetStride() const
	{
		return this->stride;
	}
};


