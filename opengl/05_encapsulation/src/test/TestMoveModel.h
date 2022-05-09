#pragma once
#include "test/Test.h"
#include "glm/glm.hpp"
#include "Shader.h"
#include "IndexBuffer.h"
#include "VertexArrayBuffer.h"
#include "Texture.h"
#include "Render.h"
namespace TkTest {

	class TestMoveModel :public Test
	{
	public:
		TestMoveModel();
		~TestMoveModel();

		void OnUpdate(float deltaTime = 0) override;

		void OnRender() override;

		void OnImGuiRender() override;

	private:
		// Õý½»¾ØÕó
		glm::mat4 prj;
		glm::vec3 trans;
		glm::mat4 model;
		glm::mat4 view;
		glm::mat4 mvp;
		IndexBuffer ibuffer;
		Shader shader;
		VertexArrayBuffer vao;
		Texture texture;
		VertexBuffer vbuffer;
		Renderer renderer;
	};
}