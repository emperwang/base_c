#include "TestMoveModel.h"

#include "imgui.h"
#include "glm/gtc/matrix_transform.hpp"

namespace TkTest
{
	struct Vec3
	{
		float x, y, z;
	};

	struct Vec2
	{
		float x, y;
	};

	struct Vertex
	{
		Vec3 Position;
		Vec2 TexCoords;
		float TexID;
	};

	unsigned int indices[] = {
		0, 1, 2,		// first triangle
		0, 2, 3,			// second triangle
		4, 5, 6,
		4, 6, 7
	};

	//float vertices[] = {
	//	// point			// textureCoords
	//	0.5f, 0.5f, 0.0f,	1.0f, 1.0f,	// top right
	//	0.5f, -0.5f, 0.0f,	1.0f, 0.0f,	// bottom right
	//	-0.5f,-0.5f, 0.0f,	0.0f, 0.0f,	// bottom left
	//	-0.5f, 0.5f, 0.0f,	0.0f, 1.0f	// top left
	//};

	static std::array<Vertex, 4> CreateQuad(float x, float y, float texId)
	{
		float size = 1.0f;
		Vertex v1;
		v1.Position = { x, y, 0.0f };
		v1.TexCoords = { 0.0f, 0.0f };
		v1.TexID = texId;

		Vertex v2;
		v2.Position = { x+size, y, 0.0f };
		v2.TexCoords = { 1.0f, 0.0f };
		v2.TexID = texId;

		Vertex v3;
		v3.Position = { x+size, y+size, 0.0f };
		v3.TexCoords = { 1.0f, 1.0f };
		v3.TexID = texId;

		Vertex v4;
		v4.Position = { x, y+size, 0.0f };
		v4.TexCoords = { 0.0f, 1.0f };
		v4.TexID = texId;

		return { v1, v2,v3,v4 };
	}

	TestMoveModel::TestMoveModel():prj(glm::mat4(1.0)), trans(glm::vec3(1.0)), model(glm::mat4(1.0)), view(glm::mat4(1.0)),
		mvp(glm::mat4(1.0)), FillMode(true)
	{
		prj = glm::ortho(-4.0f, 4.0f, -3.0f, 3.0f, -1.0f, 1.0f);
		trans = glm::vec3(1.0f, 1.0, 0);
		model = glm::translate(glm::mat4(1.0f), trans);
		view = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f));
		mvp = prj * view * model;

		// ----- init vertex
		auto verx = CreateQuad(-1.5f, -0.5f, 0.0f);
		auto verx2 = CreateQuad(-0.5f, -0.5f, 1.0f);

		Vertex vex[8];
		memcpy(vex, verx.data(), verx.size() * sizeof(Vertex));
		memcpy(vex + verx.size(), verx2.data(), verx2.size() * sizeof(Vertex));

		ibuffer = std::make_unique<IndexBuffer>(indices, 12);
		shader = std::make_unique<Shader>("assets/shader/vertex.vs", "assets/shader/fragment.fs");
		texture1 = std::make_unique<Texture>("assets/picture/container.jpg");
		texture2 = std::make_unique<Texture>("assets/picture/wall.jpg");
		renderer = std::make_unique<Renderer>();
		vao = std::make_unique<VertexArrayBuffer>();
		//vbuffer = std::make_unique<VertexBuffer>(verx.data(), verx.size()*sizeof(Vertex));
		vbuffer = std::make_unique<VertexBuffer>(vex, 8*sizeof(Vertex));

		// ------------------
		shader->Bind();
		//shader->SetUniform1i("tex1", 0);
		shader->SetUniformMat4f("u_MVP", mvp);
		int samplers[2] = { 0,1 };
		shader->SetUniform1iv("u_textures", 2, samplers);
		//shader->SetUniform1i("u_textures", 1);

		VertexBufferLayout layout;
		layout.Push<float>(3);
		layout.Push<float>(2);
		layout.Push<float>(1);
		vao->AddBuffer(*vbuffer, layout);
	}

	TestMoveModel::~TestMoveModel()
	{

	}

	void TestMoveModel::OnUpdate(float deltaTime /*= 0*/)
	{

	}

	void TestMoveModel::OnRender()
	{
		renderer->clear();
		model = glm::translate(glm::mat4(1.0f), trans);
		mvp = prj * view * model;
		vbuffer->Bind();
		texture1->Bind();
		texture2->Bind(1);
		ibuffer->Bind();
		vao->Bind();
		shader->Bind();
		shader->SetUniformMat4f("u_MVP", mvp);
		renderer->Draw(*vao, *ibuffer, *shader);
		if (FillMode)
		{
			GLCall(glPolygonMode(GL_FRONT_AND_BACK, GL_FILL));
		}
		else
		{
			GLCall(glPolygonMode(GL_FRONT_AND_BACK, GL_LINE));
		}
	}

	void TestMoveModel::OnImGuiRender()
	{
		ImGui::Text("This simple useful text");
		ImGui::SliderFloat3("Model", &trans.x, -4.0f, 4.0);
		if (ImGui::Button("switch"))
		{
			FillMode = !FillMode;
		}
	}

}