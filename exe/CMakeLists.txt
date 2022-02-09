# Minimum version of CMake required to build this project
cmake_minimum_required(VERSION 3.0)
# Name of the project
project(myproject)

set(ENV{HOME_DIR} "/home/vivek/Templates/template_cpp_project")

if (NOT CMAKE_BUILD_TYPE)
    message(STATUS "No build type selected, default to Release")
    set(CMAKE_BUILD_TYPE "Release")
endif()
message("CMAKE_SOURCE_DIR is: " ${CMAKE_SOURCE_DIR})
file(GLOB_RECURSE HEADERS ${CMAKE_SOURCE_DIR}/include/*.hpp)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/${CMAKE_BUILD_TYPE})

include_directories($ENV{HOME_DIR}/include)

#Get the correct library (default == Release)
if (CMAKE_BUILD_TYPE MATCHES Debug)
        set(LIB_SAMPLE $ENV{HOME_DIR}/lib/libsample-debug.so)
else()
        set(LIB_SAMPLE $ENV{HOME_DIR}/lib/libsample.so)
endif()

#need to use C++17
add_definitions(-std=c++17)
if ("$ENV{SAMPLE_ARCH}" STREQUAL "")
  set(CMAKE_CXX_FLAGS_RELEASE "-O3 -std=c++17 -march=native")
else()
  set(CMAKE_CXX_FLAGS_RELEASE "-O3 -std=c++17 -march=$ENV{SAMPLE_ARCH}")
endif()
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -DNDEBUG")
message("CMAKE_CXX_FLAGS_DEBUG is ${CMAKE_CXX_FLAGS_DEBUG}")
message("CMAKE_CXX_FLAGS_RELEASE is ${CMAKE_CXX_FLAGS_RELEASE}")

#Executable
set (PROG main)
set (SOURCES $ENV{HOME_DIR}/exe/${PROG}.cpp)
# Add all the source files needed to build the executable
add_executable(${PROG} ${SOURCES} ${HEADERS})
# Link the executable and the library together
target_link_libraries(${PROG} ${LIB_SAMPLE})
