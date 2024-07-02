workspace "BasicPhysicsSimulation"
    configurations { "Debug", "Release" }
	platforms { "x64", "x86" }

project "BasicPhysicsSimulation"
    kind "ConsoleApp"
    language "C++"
	cppdialect "C++latest"
    targetdir "bin/%{cfg.buildcfg}"

    files { "**.h", "**.cpp" }
	
	libdirs { "vendor/lib" }
	includedirs { "vendor/include" }

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"
		
		links {
			"sfml-graphics-d",
			"sfml-window-d",
			"sfml-system-d"
		}

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"
		
		links {
			"sfml-graphics",
			"sfml-window",
			"sfml-system"
		}
		
	filter "platforms:x64"
            architecture "x86_64"

	filter "platforms:x86"
		architecture "x86"