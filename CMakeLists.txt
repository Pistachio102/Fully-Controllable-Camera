cmake_minimum_required(VERSION 3.17)
project(GraphicsOffline)

set(CMAKE_CXX_STANDARD 14)

add_executable(GraphicsOffline 1605102_2.cpp)
set(OpenGlLinkers -lglut -lGLU -lGL)
target_link_libraries(GraphicsOffline ${OpenGlLinkers})