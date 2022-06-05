if not p.extensions.nasm then
	error("This project requires premake-nasm from https://github.com/MarcasRealAccount/premake-nasm")
end

require("Premake/Common")


workspace("rngos")
	common:setConfigsAndPlatforms()
	common:addCoreDefines()

	cppdialect("C++20")
	rtti("Off")
	exceptionhandling("Off")
	flags("MultiProcessorCompile")
	
	usenasm(true)

	startproject("rngos")

	group("Dependencies")
	group("Apps")
	project("rngos")
		location("rngos/")
		warnings("Extra")

		common:outDirs()
		common:debugDir()

		kind("ConsoleApp")

		includedirs({ "%{prj.location}/Src/" })
		files({ "%{prj.location}/Src/**" })
		removefiles({ "*.DS_Store" })


		common:addActions()
