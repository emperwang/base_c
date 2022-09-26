include "dependencies.lua"

workspace "Base-Cpp"
	characterset "MBCS"
	architecture "x64"
	configurations {"Debug", "Release"}
	flags {"MultiProcessorCompile"}

group ""


include "Base-Cpp"
include "Base-cpp3"
include "dataStruct"
include "PersonNote"
include "SpeakerGame"
include "StdLib"
include "WokerManagerSystem"
include "OrderManager"

