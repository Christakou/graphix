cmake_minimum_required(VERSION 3.28)
project(graphix)

set(CMAKE_CXX_STANDARD 20)

# Include directories
include_directories(SYSTEM ./include/ ./include/GLFW)

# Add the GLFW library path
link_directories(${CMAKE_SOURCE_DIR}/lib)

# Add the executable
add_executable(graphix src/main.cpp src/glad.c
        src/graphics/Shader.cpp
        src/graphics/Shader.h
        src/graphics/EBO.cpp
        src/graphics/EBO.h
        src/graphics/VBO.cpp
        src/graphics/VBO.h
        src/graphics/VAO.cpp
        src/graphics/VAO.h
        src/graphics/Camera.cpp
        src/graphics/Camera.h
        src/graphics/Texture.cpp
        src/graphics/Texture.h)

# Link GLFW library
target_link_libraries(graphix glfw3)