workspace "openGL"
	characterset "MBCS"
	architecture "x64"
	configurations {"Debug", "Release"}
	flags {"MultiProcessorCompile"}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
cwd = os.getcwd()
IncludeDir = {}
IncludeDir["GLFW"] = "%{cwd}/vendor/GLFW/include"
IncludeDir["glad"] = "%{cwd}/vendor/glad33/include"
IncludeDir["glm"] = "%{cwd}/vendor/glm"
IncludeDir["stb"] = "%{cwd}/vendor/stb"


group "Dependencies"
	include "vendor/GLFW"
	include "vendor/glad33"
	include "vendor/ImGui"

group ""
include "0_window"
include "01_opengl"
include "02_element_buffer"
include "03_opengl_shader"
include "04_opengl_camera"

