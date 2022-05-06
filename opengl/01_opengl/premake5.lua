project "01_opengl"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++11"

	targetdir ("../build/" .. outputdir .. "/%{prj.name}")
	objdir ("../build/" .. outputdir .. "/%{prj.name}")

	files 
	{
		"**.h",
		"**.cpp",
		"../vendor/glad33/**.h",
		"../vendor/glad33/**.c",
		"../vendor/stb/*.h"
	}


	includedirs 
	{
		"src",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.glad}",
		"%{IncludeDir.stb}"
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