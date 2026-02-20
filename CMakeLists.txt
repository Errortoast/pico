cmake_minimum_required(VERSION 3.24)
project(pico VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)

add_executable(pico main.cpp)

find_package(Curses REQUIRED)
target_link_libraries(pico PRIVATE ${CURSES_LIBRARIES})
target_include_directories(pico PRIVATE ${CURSES_INCLUDE_DIR})