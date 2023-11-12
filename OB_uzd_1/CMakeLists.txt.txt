cmake_minimum_required(VERSION 3.13)  # CMake version check
project(OB_uzd_v1)               # Create project "simple_example"
set(CMAKE_CXX_STANDARD 14)            # Enable c++14 standard
include_directories(include)
file(GLOB SOURCES "src/*.cpp")
# Add executable target with source files listed in SOURCE_FILES variable
add_executable(OB_uzd_v1 ${SOURCE_FILES})