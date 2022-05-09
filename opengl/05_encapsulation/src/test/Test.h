#pragma once
#include <vector>
#include <functional>
#include <string>
namespace TkTest {
	
	class Test
	{
	public:
		Test() {}
		virtual	~Test(){}

		virtual void OnUpdate(float deltaTime){}

		virtual void OnRender(){}

		virtual void OnImGuiRender(){}
	};

	class TestMenu : public Test
	{
	public:
		TestMenu(Test*& testPointer);
		~TestMenu();
		
		void OnImGuiRender() override;

		void OnRender() override;

		template<typename T>
		void RegisterTest(const std::string& name)
		{
			tests.push_back(std::make_pair(name, []() {return new T(); }));
		}

	private:
		Test*& currentTest;
		std::vector<std::pair<std::string, std::function<Test* ()>>> tests;
	};
}
