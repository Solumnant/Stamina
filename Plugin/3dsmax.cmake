# implementation based on https://github.com/PredatorCZ/PreCore/blob/cb5b10810f317f944d3797fcbe7574f001c7a207/cmake/3dsmax.cmake

if (NOT DEFINED MAX_VERSION)
	set (MAX_VERSION 2016)
endif()


if (MAX_VERSION GREATER 2012)
    add_definitions(-D_UNICODE -DUNICODE)
    set(CHAR_TYPE UNICODE)
else()
    set(CHAR_TYPE CHAR)
endif()

set(MaxDirectory "C:/Program Files/Autodesk/3ds Max ${MAX_VERSION}")
set (MaxPlugins "${MaxDirectory}/plugins")


set ( MAXSDK__HEADERS_DIR "${MaxDirectory} SDK/maxsdk/include" )
set ( MAXSDK__LIBRARY_DIR "${MaxDirectory} SDK/maxsdk/lib/x64/release/" )

include_directories(${MAXSDK__HEADERS_DIR})
link_directories(${MAXSDK__LIBRARY_DIR})
set ( MAX_LIBS "mnmath.lib"
			   "poly.lib"
			   "paramblk2.lib"
			   "gfx.lib"
			   "core.lib"
			   "geom.lib"
			   "mesh.lib"
			   "gup.lib"
			   "menus.lib"
			   "maxutil.lib"
			   "bmm.lib"
			   "maxscrpt.lib"
			   "comctl32.lib"   
)



set(MaxProperties
    RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO ${MaxPlugins}
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${MaxPlugins}
    RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/bin/${CMAKE_GENERATOR_PLATFORM}_${MAX_VERSION}
)