#pragma once
#include <unordered_map>
#include <glm/glm.hpp>

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
	void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
	void SetUniform1i(const std::string& name, int value);
	void SetUniform1iv(const std::string& name,const int count, const int* value);
	void SetUniformMat4f(const std::string& name, const glm::mat4& value);

private:
	int GetUniformLocation(const std::string& name);
	unsigned int CompileShader(unsigned int type, const std::string& source);
	void CreateProgram(std::string& vSource, std::string& fSource);
	ShaderSource ParseShaderSource(std::string& vPath, std::string& fPath);
};
