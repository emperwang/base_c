project "08_MatchMan"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("../build/" .. outputdir .. "/%{prj.name}")
	objdir ("../bin-int/" .. outputdir .. "/%{prj.name}")

	files 
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
		"src",
		"vendor/spdlog/include"
	}

	--links

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
