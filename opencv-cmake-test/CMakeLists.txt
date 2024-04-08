cmake_minimum_required(VERSION 3.0.0)

project(openctest VERSION 0.1.0)

include(CTest)
enable_testing()

find_package(OpenCV REQUIRED)
# Include directories from OpenCV
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(opencvtest main.cpp)
# Link OpenCV libraries
target_link_libraries(opencvtest ${OpenCV_LIBS})
