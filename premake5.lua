workspace "Raven"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Raven"
	location "Raven"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	include
	{
		"%{prj.name}/vendor/spdlog/include;"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		sytemversion "10.0"

		defines
		{
			"RV_PLATFORM_WINDOWS",
			"RV_BUILD_DLL"
		}

		postbuildcommands
		{
			{"{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox"}
		}

	filter "configurations::Debug"
		defines "RV_DEBUG"
		symbols "On"

	filter "configurations::Release"
		defines "RV_RELEASE"
		optimize "On"

	filter "configurations::Dist"
		defines "RV_DIST"
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

	include
	{
		"%{prj.name}/vendor/spdlog/include;"
		"Raven/src"
	}

	links
	{
		"Raven"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		sytemversion "10.0"

		defines
		{
			"RV_PLATFORM_WINDOWS",
		}

	filter "configurations::Debug"
		defines "RV_DEBUG"
		symbols "On"

	filter "configurations::Release"
		defines "RV_RELEASE"
		optimize "On"

	filter "configurations::Dist"
		defines "RV_DIST"
		optimize "On"