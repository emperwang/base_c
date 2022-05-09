
-- opengl dependencies
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
cwd = os.getcwd()
IncludeDir = {}
IncludeDir["GLFW"] = "%{cwd}/vendor/GLFW/include"
IncludeDir["glad"] = "%{cwd}/vendor/glad33/include"
IncludeDir["glm"] = "%{cwd}/vendor/glm"
IncludeDir["stb"] = "%{cwd}/vendor/stb"
IncludeDir["ImGui"] = "%{cwd}/vendor/ImGui"