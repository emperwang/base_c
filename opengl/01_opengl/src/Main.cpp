#define GLFW_INCLUDE_NONE
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>
#include <iostream>


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
	glViewport(0, 0, 800, 600);



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
	glShaderSource(fragment_shader, 1, &fragment_shader_source, NULL);
	glCompileShader(fragment_shader);
	glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);

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

	glGetProgramiv(shader_program, GL_LINK_STATUS, &success);
	if(!success) {
		glGetProgramInfoLog(shader_program, 512, NULL, info_log);
		std::cout << "Error: Shader:Program:Link failed.\n" << info_log << std::endl;
		return;
	}

	glDeleteShader(vertex_shader);
	glDeleteShader(fragment_shader);


	float vertices[] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f, 0.5f, 0.0f
	};

	unsigned int VBO, VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glGenBuffers(1, &VBO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// unbind
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	// max attributes
	int nr_attributes_count;
	glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nr_attributes_count);
	std::cout << "Maximum number of vertex attributes support: " << nr_attributes_count << std::endl;

	// load image
	int width, height, nr_channels;
	unsigned char* data = stbi_load("assets/picture/container.jpg", &width, &height, &nr_channels, 0);
	std::cout << "width: " << width << ", height: " << height << ", channels: " << nr_channels << std::endl;


	stbi_image_free(data);
	while (!glfwWindowShouldClose(window)) {
		process_input(window);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		
		glUseProgram(shader_program);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window);
		glfwPollEvents();

	}

	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteProgram(shader_program);

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
