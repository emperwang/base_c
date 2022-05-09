#pragma once

#include "VertexArrayBuffer.h"
#include "IndexBuffer.h"
#include "Shader.h"
// __debugbreak��� MVCS ��ϵ�
#define ASSERT(x)  if(!(x)) __debugbreak();

#define GLCall(x)  GLClearError();  x;  ASSERT(GLLogCall(#x, __FILE__,__LINE__));


void GLClearError();

// ���쳣,�򷵻�false
bool GLLogCall(const char* function, const char* file, const int line);

class Renderer 
{
private:

public:
	Renderer() {}
	~Renderer(){}

	void clear() const;

	void Draw(VertexArrayBuffer& Vao, IndexBuffer& ibuffer, Shader& shader) const;
};