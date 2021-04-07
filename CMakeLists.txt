# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("Stamina")

# Include sub-projects.
#add_subdirectory ("Stamina")

#add_subdirectory("Client")
add_subdirectory("Stamina")
add_subdirectory("Shared")
add_subdirectory("Plugin")

