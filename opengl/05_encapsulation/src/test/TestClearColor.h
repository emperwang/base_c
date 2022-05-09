#pragma once
#include "Test.h"

namespace TkTest {

	class TestClearColor: public Test
	{
	public:
		TestClearColor();
		~TestClearColor();
		void OnUpdate(float deltaTime = 0.0f) override;

		void OnRender() override;

		void OnImGuiRender() override;
	private:
		float m_clearColor[4];
	};
}
