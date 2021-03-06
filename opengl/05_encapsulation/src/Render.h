#pragma once

#include "VertexArrayBuffer.h"
#include "IndexBuffer.h"
#include "Shader.h"
// __debugbreak针对 MVCS 打断点
#define ASSERT(x)  if(!(x)) __debugbreak();

#define GLCall(x)  GLClearError();  x;  ASSERT(GLLogCall(#x, __FILE__,__LINE__));


void GLClearError();

// 有异常,则返回false
bool GLLogCall(const char* function, const char* file, const int line);

class Renderer 
{
private:

public:
	Renderer() {}
	~Renderer(){}

	void clear() const;
	void clear(const float r, const float g, const float b, const float alpha) const;

	void Draw(VertexArrayBuffer& Vao, IndexBuffer& ibuffer, Shader& shader) const;
};