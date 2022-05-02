workspace "Project_easyX"
	characterset "MBCS"
	architecture "x64"
	configurations {"Debug", "Release"}
	flags {"MultiProcessorCompile"}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "08_MatchMan"
include "07_oneHundred"
include "06_needle"
include "05_tensteps"
include "03_interest_c"
include "03_greedySnake"
include "02_pushBox"
include "01_easyx"

