#pragma once

// __debugbreak针对 MVCS 打断点
#define ASSERT(x)  if(!(x)) __debugbreak();

#define GLCall(x)  GLClearError();  x;  ASSERT(GLLogCall(#x, __FILE__,__LINE__));


void GLClearError();

// 有异常,则返回false
bool GLLogCall(const char* function, const char* file, const int line);