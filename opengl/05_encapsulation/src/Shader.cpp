#include "Shader.h"
#include "Render.h"
#include "glad/glad.h"

#include <fstream>
#include <sstream>
#include <iostream>

Shader::Shader(std::string vertex, std::string fragment):vertexPath(vertex), fragmantPath(fragment)
{
	ShaderSource source = ParseShaderSource(this->vertexPath, this->fragmantPath);
	CreateProgram(source.vertexSource, source.fragementSource);
}

Shader::~Shader()
{
	GLCall(glDeleteProgram(m_RenderId));
}

void Shader::Bind() const
{
	GLCall(glUseProgram(m_RenderId));
}

void Shader::Unbind() const
{
	GLCall(glUseProgram(0));
}

void Shader::SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3)
{
	GLCall(glUniform4f(GetUniformLocation(name), v0, v1, v2, v3));
}

void Shader::SetUniform1i(const std::string& name, int value)
{
	GLCall(glUniform1i(GetUniformLocation(name), value));
}

void Shader::SetUniform1iv(const std::string& name, const int count, const int* value)
{
	GLCall(glUniform1iv(GetUniformLocation(name),count, value));
}

void Shader::SetUniformMat4f(const std::string& name, const glm::mat4& value)
{
	GLCall(glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, &value[0][0]));
}

int Shader::GetUniformLocation(const std::string& name)
{
	if (this->m_unformLocationCache.find(name) != m_unformLocationCache.end())
	{
		return m_unformLocationCache[name];
	}

	GLCall(int location = glGetUniformLocation(m_RenderId, name.c_str()));
	if (location == -1)
	{
		std::cout << "Error: invalid " << name << " Location: " << location << std::endl;
	}
	m_unformLocationCache[name] = location;
	return location;
}

unsigned int Shader::CompileShader(unsigned int type, const std::string& source)
{
	unsigned int vertex = glCreateShader(type);
	const char* vs = source.c_str();
	glShaderSource(vertex, 1, &vs, NULL);
	glCompileShader(vertex);
	int success = 1;
	GLCall(glGetShaderiv(vertex, GL_COMPILE_STATUS, &success));
	if (success == GL_FALSE) {
		int length = 0;
		glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &length);
		char* message = (char*)alloca(length * sizeof(char));
		GLCall(glGetShaderInfoLog(vertex, length, &length, message));
		std::cout << "Error:Shader:Vertex:Compile_failed.\n" << message << std::endl;
	}
	return vertex;
}

void Shader::CreateProgram(std::string& vSource, std::string& fSource)
{
	unsigned int vShader = CompileShader(GL_VERTEX_SHADER, vSource);
	unsigned int fShader = CompileShader(GL_FRAGMENT_SHADER, fSource);
	GLCall(m_RenderId = glCreateProgram());
	GLCall(glAttachShader(m_RenderId, vShader));
	GLCall(glAttachShader(m_RenderId, fShader));
	GLCall(glLinkProgram(m_RenderId));
	GLCall(glValidateProgram(m_RenderId));
	int success = 1;
	GLCall(glGetProgramiv(m_RenderId, GL_LINK_STATUS, &success));
	if (success == GL_FALSE) {
		int length = 0;
		glGetShaderiv(m_RenderId, GL_INFO_LOG_LENGTH, &length);
		char* message = (char*)alloca(length * sizeof(char));
		glGetProgramInfoLog(m_RenderId, length, &length, message);
		std::cout << "Error:Shader:Link_Failed. " << message << std::endl;
	}
	GLCall(glDeleteShader(vShader));
	GLCall(glDeleteShader(fShader));
}

ShaderSource Shader::ParseShaderSource(std::string& vPath, std::string& fPath)
{
	std::ifstream vertex(vPath);
	std::ifstream fragement(fPath);

	std::stringstream vString, fString;
	vString << vertex.rdbuf();
	fString << fragement.rdbuf();

	vertex.close();
	fragement.close();
	ShaderSource source;
	source.fragementSource = fString.str();
	source.vertexSource = vString.str();
	return source;
}
