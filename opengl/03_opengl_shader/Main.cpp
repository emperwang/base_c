#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>
#include <iostream>
#include "Shader.h"

const char* fragment_shader_source2 = "#version 330 core \n"
"out vec4 FragColor; \n"
"in vec4 vertex_color; \n"
"uniform vec4 our_color; \n"
"void main() { \n"
"FragColor = our_color; } \0";

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

	// max attributes
	int nr_attributes;
	glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nr_attributes);
	std::cout << "Maximun nr of vertex attributes supported: " << nr_attributes << std::endl;

	Shader shader("shader.vs", "shader.fs");


	float vertices[] = {
		// position			colors		       texture coords
		0.5f, 0.5f, 0.0f,	1.0f, 0.0f, 0.0f,    1.0f, 1.0f,	// top right
		0.5f, -0.5f, 0.0f,	0.0f, 1.0f, 0.0f,    1.0f, 0.0f,	// bottom right
		-0.5f,-0.5f, 0.0f,	0.0f, 0.0f, 1.0f,    0.0f, 0.0f,	// bottom left
		-0.5f, 0.5f, 0.0f,	1.0f, 1.0f, 0.0f,    0.0f, 1.0f	// top left
	};

	float triangles[] = {
		// position			// colors
		0.5,  -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,		// bottom right
		-0.5, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,	// bottom left
		0.0f, 0.5f,  0.0f, 0.0f, 0.0f, 1.0f		// top

	};

	unsigned int indices[] = {
		0, 1, 3,		// first triangle
		1, 2, 3			// second triangle
	};

	unsigned int EBO, VAO, VBO;		// element buffer object
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &EBO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3* sizeof(float)));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);


	unsigned int texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	std::string img_path = "container.jpg";
	int img_width, img_height, img_nr_channels;
	
	stbi_set_flip_vertically_on_load(true);

	unsigned char* img_data = stbi_load(img_path.c_str(), &img_width, &img_height, &img_nr_channels, 0);
	if (img_data) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img_width, img_height, 0, GL_RGB, GL_UNSIGNED_BYTE, img_data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else {
		std::cout << "Failed to load image." << std::endl;
	}
	stbi_image_free(img_data);
	// unbind
	//glBindBuffer(GL_ARRAY_BUFFER, 0);
	//glBindVertexArray(0);

	unsigned int texture2;
	glGenTextures(1, &texture2);
	glBindTexture(GL_TEXTURE_2D, texture2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	std::string img2_path = "awesomeface.png";
	img_data = stbi_load(img2_path.c_str(), &img_width, &img_height, &img_nr_channels, 0);
	if (img_data) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img_width, img_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, img_data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else {
		std::cout << "Failed to load image2." << std::endl;
	}

	stbi_image_free(img_data);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
	shader.use();
	// set texture 
	glUniform1i(glGetUniformLocation(shader.ID, "texture1"), 0);
	shader.setInt("texture2", 1);

	while (!glfwWindowShouldClose(window)) {
		process_input(window);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		

		float time_value = static_cast<float>(glfwGetTime());
		float green_value = (sin(time_value) / 2.0f) + 0.5f;
		//int out_color_location = glGetUniformLocation(shader_program, "our_color");
		//glUseProgram(shader_program);
		//glUniform4f(out_color_location, 0.0f, green_value,0.0f,1.0f);
		
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, texture2);

		shader.use();
		glBindVertexArray(VAO);
		//glDrawArrays(GL_TRIANGLES, 0, 3);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(window);
		glfwPollEvents();

	}

	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	//glDeleteProgram(shader_program);

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
