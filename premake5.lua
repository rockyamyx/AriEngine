workspace "AriEngine"
	
	architecture "x64"
	startproject "Sandbox"

	platforms
	{
		"Windows"
	}
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
				-- 	(Debug/Release/Dist)-(WIN/MAC_OS/ect)-(86/64)
	outputdir =  "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"


	IncludeDir = {}
	IncludeDir["GLFW"] = "AriEngine/vendor/GLFW/include"

	include "AriEngine/vendor/GLFW/"

	group "Dependencies"

	group ""

	project "AriEngine"
		location "AriEngine"
		kind "SharedLib"
		language "C++"
		cppdialect"C++17"
		staticruntime "On"

		targetdir ("bin/" .. outputdir .. "/%{prj.name}" )
		objdir ("bin-int/" .. outputdir .. "/%{prj.name}" )

		pchheader "aepch.h"
		pchsource "AriEngine/src/aepch.cpp"

		files
		{
			"%{prj.name}/src/**.h",
			"%{prj.name}/src/**.cpp",
		}

		defines
		{
			
		}

		includedirs
		{
			"%{prj.name}/src",
			"%{prj.name}/vendor/spdlog/include",
			"%{IncludeDir.GLFW}"
		}

		links
		{
			"GLFW",
			"opengl32.lib"
		}

		postbuildcommands {
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .."/Sandbox")
		}
		
		filter "platforms:Windows"
			systemversion "10.0.17763.0"

			defines
			{
				"AE_PLATFORM_WINDOWS",
				"AE_BUILD_DLL"
			}

		filter "configurations:Debug"
			defines "AE_DEBUG"
			
			symbols "On"

		filter "configurations:Release"
			defines "AE_RELEASE"
			optimize "On"

		filter "configurations:Dist"
			defines "AE_DIST"
			optimize "On"

			
		
			
			
			--- SANDBOX ---


	project "Sandbox"

		location "Sandbox"
		kind "ConsoleApp"
		language "C++"
		cppdialect "C++17"
		staticruntime "On"

		targetdir ("bin/" .. outputdir .. "/%{prj.name}" )
		objdir ("bin-int/" .. outputdir .. "/%{prj.name}" )

		files
		{
			"%{prj.name}/src/**.h",
			"%{prj.name}/src/**.cpp"
		}

		includedirs
		{
			"AriEngine/vendor/spdlog/include",
			"AriEngine/src",
			"AriEngine/vendor"

		}

		links
		{
			"AriEngine"
		}

		filter "platforms:Windows"
			systemversion "10.0.17763.0"
			defines
			{
				"AE_PLATFORM_WINDOWS"
			}

		filter "configurations:Debug"
			defines "AE_DEBUG"
			symbols "On"

		filter "configurations:Release"
			defines "AE_RELEASE"
			optimize "On"

		filter "configurations:Dist"
			defines "AE_DIST"
			optimize "On"
