project "Runtime"
    kind "SharedLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "off"
    
    targetdir ("{%wks.location}/bin" .. outputdir .. "/%{prj.name}")
    objdir ("{%wks.location}/bin-int" .. outputdir .. "/%{prj.name}")

    files
    {
        "src/**.h",
        "src/**.cpp"
    }

    defines
    {
        "RUNTIME_EXPORT"
    }

    includedirs
    {
        "src",
        "%{IncludeDir.VulkanSDK}",
        "%{IncludeDir.LLGL}"
    }

    links
    {
        "%{Library.LLGL}",
        "%{Library.Vulkan}",
        "ELGR"
    }

    filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines "HZ_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "HZ_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "HZ_DIST"
		runtime "Release"
		optimize "on"