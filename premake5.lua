workspace "BasicPhysicsSimulation"
    configurations { "Debug", "Release" }

project "BasicPhysicsSimulation"
    kind "ConsoleApp"
    language "C++"
    targetdir "bin/%{cfg.buildcfg}"

    files { "**.h", "**.cpp" }

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"