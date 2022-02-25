# cmake version minimum
cmake_minimum_required(VERSION 2.8)

# project name
project(cpp_template)

# setting binary and library file output directory
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)    

# setting compile mode
set(CMAKE_BUILD_TYPE "Debug")

# setting c++11 support
set(CMAKE_CXX_FLAGS "-std=c++11 -O0")

# setting self project include and library directories
include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)

# add cmake sub-directories
add_subdirectory(src)