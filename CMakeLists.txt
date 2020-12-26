cmake_minimum_required(VERSION 2.4)

project(have_some_pi)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

include_directories(${PROJECT_SOURCE_DIR})

add_executable(have_some_pi main.cpp)

target_link_libraries(
    have_some_pi 
    wiringPi 
    pthread
)