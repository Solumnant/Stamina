add_library(Stamina SHARED "src/core/Stamina.cpp" "src/core/Stamina.h" "src/xml/Xml.h" "src/rapidxml/rapidxml.hpp" "src/rapidxml/rapidxml_iterators.hpp" "src/rapidxml/rapidxml_print.hpp" "src/rapidxml/rapidxml_utils.hpp" "src/rageformats/gtaDrawable.h" "src/rageformats/gtaDrawable.cpp" "src/math/Vectors.h" "src/rageformats/grmShaderGroup.cpp"  "src/rageformats/grcTexturePC.h" "src/rageformats/grcTexturePC.cpp" "src/rageformats/grmModel.h" "src/rageformats/grmModel.cpp" "src/rageformats/grmShaderFx.h" "src/utils/JenkinsHash.h" "src/rageformats/grmShaderFx.cpp" "src/rageformats/grmShaderParameter.h"  "src/rageformats/grmShaderParameter.cpp"   "src/rageformats/grmGeometryQB.h" "src/rageformats/grcVertexBuffer.h" "src/rageformats/grcIndexBuffer.h"  "src/rageformats/grmGeometryQB.cpp" "src/rageformats/grcIndexBuffer.cpp" "src/rageformats/grcVertexBuffer.cpp" "src/rageformats/grcVertexFormat.h" "src/rageformats/grcVertexFormat.cpp" "src/rageformats/CCollection.h" "src/core/RscFile.h"    "src/core/PrecompiledHeader.h" "src/core/PrecompiledHeader.cpp" "src/core/Primitives.h")
target_precompile_headers(Stamina PUBLIC src/core/PrecompiledHeader.h)
set_target_properties(Stamina 
                     PROPERTIES 
                     OUTPUT_NAME "stamina-core"
                     WINDOWS_EXPORT_ALL_SYMBOLS ON
                     RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

target_link_libraries(Stamina "Shared")
target_include_directories(Stamina PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)