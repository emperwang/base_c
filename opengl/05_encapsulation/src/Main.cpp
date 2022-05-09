#define GLFW_INCLUDE_NONE
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>
#include <iostream>

#include "Render.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArrayBuffer.h"
#include "Shader.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

void process_input(GLFWwindow *window);

void main() {

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

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

	{
		Shader shader("assets/shader/vertex.vs", "assets/shader/fragment.fs");
		VertexArrayBuffer Vao;
		VertexBuffer vbuffer(vertices, sizeof(vertices));
		VertexBufferLayout layout;
		layout.Push<float>(3);
		Vao.AddBuffer(vbuffer, layout);

		IndexBuffer ibuffer(indices, 6);

		//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		GLCall(glPolygonMode(GL_FRONT_AND_BACK, GL_LINE));

		while (!glfwWindowShouldClose(window)) {
			process_input(window);

			GLCall(glClearColor(0.2f, 0.3f, 0.3f, 1.0f));
			GLCall(glClear(GL_COLOR_BUFFER_BIT));

			shader.Bind();
			//GLCall(glUseProgram(shader_program));
			Vao.Bind();
			GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0));

			GLCall(glfwSwapBuffers(window));
			GLCall(glfwPollEvents());
		}
	}

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
