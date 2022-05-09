#include "Test.h"

#include "imgui.h"

namespace TkTest
{

	TestMenu::TestMenu(Test*& testPointer): currentTest(testPointer)
	{

	}

	TestMenu::~TestMenu()
	{
		tests.clear();
	}

	void TestMenu::OnImGuiRender()
	{
		for (auto& test : tests)
		{
			if (ImGui::Button(test.first.c_str()))
			{
				currentTest = test.second();
			}
		}
	}

	void TestMenu::OnRender()
	{

	}

}