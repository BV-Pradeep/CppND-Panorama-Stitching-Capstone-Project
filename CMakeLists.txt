cmake_minimum_required(VERSION 3.7)
project(Panorama_Stitching)

add_definitions(-std=c++17)
set(CXX_FLAGS "-Wall" "-pedantic")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

find_package(OpenCV 4.1 REQUIRED)
include_directories(include)
include_directories(${OpenCV_INCLUDE_DIRS})
link_directories(${OpenCV_LIBRARY_DIRS})
add_definitions(${OpenCV_DEFINITIONS})

add_executable(Panorama_Stitching src/Panorama_Stitching.cpp src/preprocessor.cpp)
target_link_libraries(Panorama_Stitching ${OpenCV_LIBS})

