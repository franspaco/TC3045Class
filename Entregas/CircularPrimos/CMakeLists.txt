cmake_minimum_required(VERSION 3.6)
project(Primos)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c)
add_executable(Primos ${SOURCE_FILES})

target_link_libraries(Primos m)