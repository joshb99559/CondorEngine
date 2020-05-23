workspace "Condor"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

    startproject "Sandbox"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Condor"
    location "Condor"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines 
        {
            "CD_PLATFORM_WINDOWS",
            "CD_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }
    
    filter "configurations:Debug"
        defines "CD_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "CD_RELEASE"
        optimize "On"
        
    filter "configurations:Dist"
        defines "CD_DIST"
        optimize "On"


project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

        
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "Condor/vendor/spdlog/include",
        "Condor/src"
    }

    links
    {
        "Condor"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines 
        {
            "CD_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "CD_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "CD_RELEASE"
        optimize "On"
        
    filter "configurations:Dist"
        defines "CD_DIST"
        optimize "On"
