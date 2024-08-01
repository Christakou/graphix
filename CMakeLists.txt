cmake_minimum_required(VERSION 3.28)
project(graphix)

set(CMAKE_CXX_STANDARD 20)

# Include directories
include_directories(SYSTEM ./include/ ./include/GLFW)

# Add the GLFW library path
link_directories(${CMAKE_SOURCE_DIR}/lib)

# Add the executable
add_executable(graphix src/main.cpp src/glad.c)

# Link GLFW library
target_link_libraries(graphix glfw3)