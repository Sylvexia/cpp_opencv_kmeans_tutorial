cmake_minimum_required(VERSION 3.10)

project(basic_tutorial)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(ch1 ch1_meow.cpp)

target_link_libraries(ch1 ${OpenCV_LIBRARIES})