project "03_greedySnake"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("../build/" .. outputdir .. "/%{prj.name}")
	objdir ("../bin-int/" .. outputdir .. "/%{prj.name}")

	files 
	{
		"**.h",
		"**.cpp",
		"src/**.h",
		"src/**.cpp"
	}

	filter "system:windows"
		systemversion "latest"
		defines {"GL_PLATFORM_WINDOWS"}

	filter "configurations:Debug"
		defines "DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "RELEASE"
		runtime "Release"
		optimize "on"