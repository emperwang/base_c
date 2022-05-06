#pragma once

class IndexBuffer
{
private:
	unsigned int m_RenderId;
	unsigned int m_count;
public:
	IndexBuffer(const unsigned int* data, unsigned int count);
	~IndexBuffer();

	void Bind() const;
	void unBind() const;
};
