# Minimum version of CMake required to build this project
cmake_minimum_required(VERSION 3.0)
# Name of the project
project(sample_release)

set(ENV{HOME_DIR} "/home/vivek/Templates/template_cpp_project")

if (NOT CMAKE_BUILD_TYPE)
    message(STATUS "No build type selected, default to Release")
    set(CMAKE_BUILD_TYPE "Release")
endif()

set(CMAKE_MODULE_PATH $ENV{HOME_DIR}/build_release)
message("module path:" ${CMAKE_MODULE_PATH})
#Get all the src files
file(GLOB_RECURSE SAMPLE_SOURCES $ENV{HOME_DIR}/src/*.cpp )
message ("Source files" : ${SAMPLE_SOURCES})
include_directories($ENV{HOME_DIR}/include)

#need to use C++17
add_definitions(-std=c++17)
if ("$ENV{SAMPLE_ARCH}" STREQUAL "")
  set(CMAKE_CXX_FLAGS_RELEASE "-O3 -std=c++17")
else()
  set(CMAKE_CXX_FLAGS_RELEASE "-O3 -march=$ENV{SAMPLE_ARCH} -std=c++17")
endif()

# Add a library to this build. The name of the library is MyLibrary and it
# consists of only the MyLibrary.cpp file. `SHARED`: `.so` - shared or dynamic lib.
add_library(sample SHARED ${SAMPLE_SOURCES})
# ARCHIVE_OUTPUT_DIRECTORY for static library
set_target_properties(sample PROPERTIES LIBRARY_OUTPUT_DIRECTORY $ENV{HOME_DIR}/lib COMPILE_FLAGS "-fPIC")
message("CMAKE_CXX_FLAGS_RELEASE is ${CMAKE_CXX_FLAGS_RELEASE}")
