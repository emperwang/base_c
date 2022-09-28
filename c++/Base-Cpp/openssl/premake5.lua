project "openssl"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++11"
	--staticruntime "on"

	targetdir ("../build/" .. outputdir .. "/%{prj.name}")
	objdir ("../bin-int/" .. outputdir .. "/%{prj.name}")

	files 
	{
		"src/**.h",
		"src/**.cpp",
	}
	
	libdirs 
	{
		"%{cwd}/vendor/openssl-1.1/x64/lib/",
		"%{cwd}/vendor/openssl-1.1/x64/lib/",
	}
	
	links 
	{
		--"opengl32.lib"
		"libcrypto.lib",
		"libssl.lib",
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs 
	{
		"src",
		IncludeDir["openssl64"]
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