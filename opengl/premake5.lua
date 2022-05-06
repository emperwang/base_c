include "dependencies.lua"

workspace "openGL"
	characterset "MBCS"
	architecture "x64"
	configurations {"Debug", "Release"}
	flags {"MultiProcessorCompile"}

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
include "05_encapsulation"

