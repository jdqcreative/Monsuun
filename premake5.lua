workspace "Monsuun2024"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Monsuun2024/vendor/GLFW/include"

include "Monsuun2024/vendor/GLFW"

project "Monsuun2024"
	location "Monsuun2024"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "mupch.h"
	pchsource "Monsuun2024/src/mupch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include;",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib",
		"dwmapi.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"MO_PLATFORM_WINDOWS",
			"MONSUUN_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "MO_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "MO_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "MO_DIST"
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
		"Monsuun2024/vendor/spdlog/include;",
		"Monsuun2024/src"
	}

	links
	{
		"Monsuun2024"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"MO_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "MO_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "MO_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "MO_DIST"
		optimize "On"