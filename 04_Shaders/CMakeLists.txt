# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.16)

# Define project name and version
project(Tutorial VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find OpenGL
find_package(OpenGL REQUIRED)

#Find GLFW
find_package(glfw3 REQUIRED)

# Find SDL2
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Add GLAD (Manually add the glad source file)
add_library(glad STATIC glad.c)
target_include_directories(glad PRIVATE include)

# Add an executable target
add_executable(GRAPHICS_APP graphics_app.cpp)

# Link OpenGL, SDL2, GLFW, and GLAD to the target
target_include_directories(GRAPHICS_APP PRIVATE ${OPENGL_INCLUDE_DIRS} ${SDL2_INCLUDE_DIRS} ${GLFW_INCLUDE_DIRS} include)
target_link_libraries(GRAPHICS_APP PRIVATE ${OPENGL_LIBRARIES} ${SDL2_LIBRARIES} glfw glad)
