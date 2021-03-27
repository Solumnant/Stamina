include(${CMAKE_CURRENT_SOURCE_DIR}/3dsmax.cmake)


add_library(Plugin SHARED "src/DllEntry.cpp" "src/Plugin.def")

target_include_directories(Plugin PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

target_link_libraries(Plugin ${MAX_LIBS} Stamina)

set_target_properties(Plugin PROPERTIES SUFFIX .dli ${MaxProperties})