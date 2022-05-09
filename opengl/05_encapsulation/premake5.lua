project "05_encapsulation"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++11"

	targetdir ("../build/" .. outputdir .. "/%{prj.name}")
	objdir ("../build/" .. outputdir .. "/%{prj.name}")

	files 
	{
		"**.h",
		"**.cpp"
	}
	
	includedirs 
	{
		"src",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.glad}",
		"%{IncludeDir.stb}",
		"%{IncludeDir.glm}"
	}

	links
	{
		"GLFW",
		"glad33",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines "GLCORE_DEBUG"
		runtime "Debug"
		symbols "on"
	
	filter "configurations:Release"
		defines "GLCORE_RELEASE"
		runtime "Release"
		optimize "on"