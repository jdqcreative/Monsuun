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
IncludeDir["Glad"] = "Monsuun2024/vendor/Glad/include"
IncludeDir["ImGui"] = "Monsuun2024/vendor/imgui"
IncludeDir["glm"] = "Monsuun2024/vendor/glm"
IncludeDir["stb_image"] = "Monsuun2024/vendor/stb_image"

include "Monsuun2024/vendor/GLFW"
include "Monsuun2024/vendor/Glad"
include "Monsuun2024/vendor/imgui"

project "Monsuun2024"
	location "Monsuun2024"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "mupch.h"
	pchsource "Monsuun2024/src/mupch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/stb_image/**.h",
		"%{prj.name}/vendor/stb_image/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl",
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include;",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb_image}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib",
		"dwmapi.lib"
	}

	filter "system:windows"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"MO_PLATFORM_WINDOWS",
			"MONSUUN_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "MO_DEBUG"
		buildoptions "/MDd"
		symbols "on"

	filter "configurations:Release"
		defines "MO_RELEASE"
		buildoptions "/MD"
		optimize "on"

	filter "configurations:Dist"
		defines "MO_DIST"
		buildoptions "/MD"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

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
		"Monsuun2024/src",
		"Monsuun2024/vendor",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Monsuun2024"
	}

	filter "system:windows"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"MO_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "MO_DEBUG"
		buildoptions "/MDd"
		symbols "on"

	filter "configurations:Release"
		defines "MO_RELEASE"
		buildoptions "/MD"
		optimize "on"

	filter "configurations:Dist"
		defines "MO_DIST"
		buildoptions "/MD"
		optimize "on"