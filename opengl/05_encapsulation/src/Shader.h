#pragma once
#include <unordered_map>

struct ShaderSource
{
	std::string vertexSource;
	std::string fragementSource;
};

class Shader
{
private:
	unsigned int m_RenderId;
	std::unordered_map<std::string, int> m_unformLocationCache;
	std::string vertexPath;
	std::string fragmantPath;

public:
	Shader(std::string vertex, std::string fragment);
	~Shader();


	void Bind() const;
	void Unbind() const;


private:
	int GetUniformLocation(std::string& name);
	unsigned int CompileShader(unsigned int type, const std::string& source);
	void CreateProgram(std::string& vSource, std::string& fSource);
	ShaderSource ParseShaderSource(std::string& vPath, std::string& fPath);
};
