include(${CMAKE_CURRENT_SOURCE_DIR}/3dsmax.cmake)


add_library(Plugin SHARED "src/DllEntry.cpp" "src/Plugin.def" "src/ResourceImporter.h" "src/ResourceImporter.cpp" "src/StaminaMax.h" "src/StaminaMax.cpp" "src/menu/StaminaMenu.cpp" "src/resource.rc" "src/resource.h")

target_include_directories(Plugin PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

target_link_libraries(Plugin ${MAX_LIBS} Stamina Shared)

set_target_properties(Plugin PROPERTIES SUFFIX .dli OUTPUT_NAME "stamina-max" ${MaxProperties})