add_library(Stamina SHARED "src/Stamina.cpp" "src/Stamina.h" "src/Xml.h" "src/rapidxml/rapidxml.hpp" "src/rapidxml/rapidxml_iterators.hpp" "src/rapidxml/rapidxml_print.hpp" "src/rapidxml/rapidxml_utils.hpp" "src/rageformats/gtaDrawable.h" "src/rageformats/gtaDrawable.cpp" "src/math/Vectors.h" "src/rageformats/grmShaderGroup.cpp" "src/rageformats/grcTextureDictionary.h" "src/rageformats/grcTexturePC.h" "src/rageformats/grcTextureDictionary.cpp" "src/rageformats/grcTexturePC.cpp" "src/rageformats/grmModel.h" "src/rageformats/grmModel.cpp" "src/rageformats/grmShaderFx.h" "src/utils/hash.h" "src/rageformats/grmShaderFx.cpp" "src/rageformats/grmShaderArray.h" "src/rageformats/grmShaderArray.cpp" "src/rageformats/grmShaderParameter.h" "src/rageformats/grmShaderParameterCollection.h" "src/rageformats/grmShaderParameterCollection.cpp" "src/rageformats/grmShaderParameter.cpp"  )
set_target_properties(Stamina 
                     PROPERTIES 
                     WINDOWS_EXPORT_ALL_SYMBOLS ON
                     RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
target_include_directories(Stamina PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)