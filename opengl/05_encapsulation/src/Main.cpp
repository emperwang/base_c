#define GLFW_INCLUDE_NONE
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>
#include <iostream>
#include <cmath>
#include "Render.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArrayBuffer.h"
#include "Shader.h"
#include "Texture.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

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
		// point			// textureCoords
		0.5f, 0.5f, 0.0f,	1.0f, 1.0f,	// top right
		0.5f, -0.5f, 0.0f,	1.0f, 0.0f,	// bottom right
		-0.5f,-0.5f, 0.0f,	0.0f, 0.0f,	// bottom left
		-0.5f, 0.5f, 0.0f,	0.0f, 1.0f	// top left
	};

	unsigned int indices[] = {
		0, 1, 3,		// first triangle
		1, 2, 3			// second triangle
	};
	glfwSwapInterval(1);

	// enable blend
	GLCall(glEnable(GL_BLEND));
	GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

	// Õý½»¾ØÕó
	glm::mat4 prj = glm::ortho(-4.0f, 4.0f, -3.0f, 3.0f, -1.0f, 1.0f);

	{
		Shader shader("assets/shader/vertex.vs", "assets/shader/fragment.fs");
		shader.Bind();
		VertexArrayBuffer Vao;
		VertexBuffer vbuffer(vertices, sizeof(vertices));
		VertexBufferLayout layout;
		layout.Push<float>(3);
		layout.Push<float>(2);
		Vao.AddBuffer(vbuffer, layout);
		//shader.SetUniform4f("color", 0.8f, 0.3f, 0.8f, 1.0f);
		IndexBuffer ibuffer(indices, 6);

		Texture texture("assets/picture/container.jpg");
		texture.Bind();
		shader.SetUniform1i("tex1", 0);
		shader.SetUniformMat4f("u_MVP", prj);
		GLCall(glPolygonMode(GL_FRONT_AND_BACK, GL_FILL));
		//GLCall(glPolygonMode(GL_FRONT_AND_BACK, GL_LINE));
		
		ibuffer.unBind();
		Vao.Unbind();
		shader.Unbind();

		Renderer renderer;

		float r=0.8;
		float increment = 0.05;
		while (!glfwWindowShouldClose(window)) {
			process_input(window);

			renderer.clear();

			shader.Bind();
			//shader.SetUniform4f("color", r, 0.3f, 0.8f, 1.0f);
			shader.SetUniformMat4f("u_MVP", prj);
			if (r >= 1)
				increment = -0.05f;
			if (r <= 0)
			{
				increment = 0.05f;
			}
			r += increment;

			renderer.Draw(Vao, ibuffer, shader);
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
