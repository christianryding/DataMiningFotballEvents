cmake_minimum_required(VERSION 3.0)

project (datamining)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread")

# add headers
include_directories(include)

# add src files, with wildcard set
file(GLOB SOURCES "src/*.cpp")
 
add_executable(datamining ${SOURCES})
