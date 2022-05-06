#define GLFW_INCLUDE_NONE
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>
#include <iostream>

// __debugbreak针对 MVCS 打断点
#define ASSERT(x)  if(!(x)) __debugbreak();

#define GLCall(x)  GLClearError();  x;  ASSERT(GLLogCall(#x, __FILE__,__LINE__));


static void GLClearError()
{
	while (glGetError() != GL_NO_ERROR);
}

// 有异常,则返回false
static bool GLLogCall(const char* function, const char* file, const int line)
{
	while (GLenum error = glGetError())
	{
		std::cout << "[OpenGl error] ( 0x" << std::hex << error << " ). " << function << " "<< file << ":" << std::dec<< line << std::endl;
		return false;
	}

	return true;
}

const char *vertex_shader_source = "#version 330 core \n"
"layout(location = 0) in vec3 aPos;		\n"
"void main() {	\n"
"gl_Position = vec4(aPos.x, aPos.y, aPos.z,1.0); \n"
"}\0";

const char* fragment_shader_source = "#version 330 core \n"
"out vec4 FragColor; \n"
"void main() { \n"
"FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f); } \0";

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

void process_input(GLFWwindow *window);

void main() {

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

#ifdef _MAC_
	glfwWindowHin(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif // _MAC_

	GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL", NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return ;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		while (1);
		return;
	}
	//glViewport(0, 0, 800, 600);


	int success;
	char info_log[512] = { 0 };

	unsigned int vertex_shader;
	vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex_shader, 1, &vertex_shader_source, NULL);
	glCompileShader(vertex_shader);

	glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(vertex_shader, 512, NULL, info_log);
		std::cout << "Error: Shader:Vertex:compile failed.\n" << info_log << std::endl;
		return;
	}
	
	unsigned int fragment_shader;
	fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	GLCall(glShaderSource(fragment_shader, 1, &fragment_shader_source, NULL));
	GLCall(glCompileShader(fragment_shader));
	GLCall(glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success));

	if (!success) {
		glGetShaderInfoLog(fragment_shader, 512, NULL, info_log);
		std::cout << "Error: Shader:Fragment:compile failed.\n" << info_log << std::endl;
		return;
	}

	unsigned int shader_program;
	shader_program = glCreateProgram();

	glAttachShader(shader_program, vertex_shader);
	glAttachShader(shader_program, fragment_shader);
	glLinkProgram(shader_program);
	glValidateProgram(shader_program);
	glGetProgramiv(shader_program, GL_LINK_STATUS, &success);
	if(!success) {
		int logLength;
		glGetProgramiv(shader_program, GL_INFO_LOG_LENGTH, &logLength);
		// 在栈上动态生成array, 并用此array来存放错误日志
		char* logbuf = (char*)alloca(logLength);
		glGetProgramInfoLog(shader_program, logLength, NULL, logbuf);
		std::cout << "Error: Shader:Program:Link failed.\n" << logbuf << std::endl;
		return;
	}

	glDeleteShader(vertex_shader);
	glDeleteShader(fragment_shader);


	float vertices[] = {
		0.5f, 0.5f, 0.0f,		// top right
		0.5f, -0.5f, 0.0f,		// bottom right
		-0.5f,-0.5f, 0.0f,		// bottom left
		-0.5f, 0.5f, 0.0f		// top left
	};

	unsigned int indices[] = {
		0, 1, 3,		// first triangle
		1, 2, 3			// second triangle
	};

	unsigned int EBO, VAO, VBO;		// element buffer object
	GLCall(glGenVertexArrays(1, &VAO));
	GLCall(glGenBuffers(1, &EBO));
	GLCall(glGenBuffers(1, &VBO));

	GLCall(glBindVertexArray(VAO));

	GLCall(glBindBuffer(GL_ARRAY_BUFFER, VBO));
	GLCall(glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW));

	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO));
	GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW));

	GLCall(glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0));
	GLCall(glEnableVertexAttribArray(0));

	// unbind
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
	GLCall(glBindVertexArray(0));

	//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	GLCall(glPolygonMode(GL_FRONT_AND_BACK, GL_LINE));

	while (!glfwWindowShouldClose(window)) {
		process_input(window);

		GLCall(glClearColor(0.2f, 0.3f, 0.3f, 1.0f));
		GLCall(glClear(GL_COLOR_BUFFER_BIT));
		
		GLCall(glUseProgram(shader_program));
		GLCall(glBindVertexArray(VAO));
		
		GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0));

		GLCall(glfwSwapBuffers(window));
		GLCall(glfwPollEvents());

	}

	GLCall(glDeleteVertexArrays(1, &VAO));
	GLCall(glDeleteBuffers(1, &VBO));
	GLCall(glDeleteBuffers(1, &EBO));
	GLCall(glDeleteProgram(shader_program));

	glfwTerminate();

	return;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}


void process_input(GLFWwindow *window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}
