cmake_minimum_required(VERSION 2.8.12)

project(tera)

# while compiling set this option to ON to enable debugging
option(T_DEBUG "Compile with debug symbols" OFF)

if(T_DEBUG)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# required for Linux and apple, since they use different compilers. GCC is linux default while macos uses llvm.
if(UNIX)
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif()
if(APPLE)
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
endif()

# location of include directory
include_directories("${PROJECT_SOURCE_DIR}/include")
# name of executable and the files required for it
add_executable(teradata src/main.cpp src/api.cpp)
