#include "TestMoveModel.h"

#include "imgui.h"
#include "glm/gtc/matrix_transform.hpp"

namespace TkTest
{

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

	TestMoveModel::TestMoveModel():prj(glm::mat4(1.0)), trans(glm::vec3(1.0)), model(glm::mat4(1.0)), view(glm::mat4(1.0)),
		mvp(glm::mat4(1.0)), ibuffer(indices, 6), shader("assets/shader/vertex.vs", "assets/shader/fragment.fs"),
		texture("assets/picture/container.jpg"), vbuffer(vertices, sizeof(vertices))
	{
		prj = glm::ortho(-4.0f, 4.0f, -3.0f, 3.0f, -1.0f, 1.0f);
		trans = glm::vec3(2.0f, 0.5, 0);
		model = glm::translate(glm::mat4(1.0f), trans);
		view = glm::translate(glm::mat4(1.0f), glm::vec3(-1.0f, 0.0f, 0.0f));
		mvp = prj * view * model;

		// ------------------
		shader.Bind();
		//VertexBuffer vbuffer(vertices, sizeof(vertices));
		VertexBufferLayout layout;
		layout.Push<float>(3);
		layout.Push<float>(2);
		vao.AddBuffer(vbuffer, layout);

		texture.Bind();
		shader.SetUniform1i("tex1", 0);
		shader.SetUniformMat4f("u_MVP", mvp);
	}

	TestMoveModel::~TestMoveModel()
	{

	}

	void TestMoveModel::OnUpdate(float deltaTime /*= 0*/)
	{

	}

	void TestMoveModel::OnRender()
	{
		renderer.clear();
		model = glm::translate(glm::mat4(1.0f), trans);
		mvp = prj * view * model;
		vbuffer.Bind();
		texture.Bind();
		ibuffer.Bind();
		vao.Bind();
		shader.Bind();
		shader.SetUniformMat4f("u_MVP", mvp);
		renderer.Draw(vao, ibuffer, shader);
	}

	void TestMoveModel::OnImGuiRender()
	{
		ImGui::Text("This simple useful text");
		ImGui::SliderFloat3("Model", &trans.x, -4.0f, 4.0);
	}

}