#pragma once

// __debugbreak��� MVCS ��ϵ�
#define ASSERT(x)  if(!(x)) __debugbreak();

#define GLCall(x)  GLClearError();  x;  ASSERT(GLLogCall(#x, __FILE__,__LINE__));


void GLClearError();

// ���쳣,�򷵻�false
bool GLLogCall(const char* function, const char* file, const int line);