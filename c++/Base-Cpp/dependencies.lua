
-- opengl dependencies
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
cwd = os.getcwd()
IncludeDir = {}
IncludeDir["openssl64"]="%{cwd}/vendor/openssl-1.1/x64/include"
IncludeDir["openssl32"]="%{cwd}/vendor/openssl-1.1/x32/include"

