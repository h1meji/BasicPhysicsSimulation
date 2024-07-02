workspace "BasicPhysicsSimulation"
    configurations { "Debug", "Release" }
	platforms { "x64", "x86" }

project "BasicPhysicsSimulation"
    kind "ConsoleApp"
    language "C++"
	cppdialect "C++latest"
    targetdir "bin/%{cfg.buildcfg}"

    files { "**.h", "**.cpp" }

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"
		
	filter "platforms:x64"
            architecture "x86_64"

	filter "platforms:x86"
		architecture "x86"