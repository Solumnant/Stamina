add_library(Shared SHARED "src/time/timestamp.h"  "src/time/timestamp.cpp")
set_target_properties(Shared 
                     PROPERTIES 
                     OUTPUT_NAME "stamina-shared"
                     WINDOWS_EXPORT_ALL_SYMBOLS ON
                     RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
target_include_directories(Shared PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)