cmake_minimum_required(VERSION 3.28)
project(LearnOpenGL)

set(CMAKE_CXX_STANDARD 17)

add_executable(LearnOpenGL main.cpp
        glad.c
        Shader.hpp)

find_package(OpenGL REQUIRED)
target_link_libraries(LearnOpenGL PRIVATE OpenGL::GL)

find_package(glad CONFIG REQUIRED)
target_link_libraries(LearnOpenGL PRIVATE glad::glad)

find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(LearnOpenGL PRIVATE glfw)
