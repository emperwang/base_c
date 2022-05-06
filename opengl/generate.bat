@echo on

cp vendor\premakefile\GLFW.lua  vendor\GLFW\premake5.lua
cp vendor\premakefile\ImGui.lua  vendor\ImGui\premake5.lua
vendor\premake\premake5.exe   vs2019

pause