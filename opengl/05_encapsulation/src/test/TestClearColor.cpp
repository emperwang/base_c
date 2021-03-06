#include "TestClearColor.h"
#include "Render.h"
#include "glad/glad.h"
#include "imgui.h"

namespace TkTest {

	TestClearColor::TestClearColor():m_clearColor{0.2f, 0.5f,0.8f,1.0f}
	{

	}

	TestClearColor::~TestClearColor()
	{

	}

	void TestClearColor::OnUpdate(float deltaTime)
	{

	}

	void TestClearColor::OnRender()
	{
		GLCall(glClearColor(m_clearColor[0], m_clearColor[1], m_clearColor[2], m_clearColor[3]));
		GLCall(glClear(GL_COLOR_BUFFER_BIT));
	}

	void TestClearColor::OnImGuiRender()
	{
		ImGui::ColorEdit4("clear color", m_clearColor);
	}
}