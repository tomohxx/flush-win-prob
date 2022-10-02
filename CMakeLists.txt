cmake_minimum_required(VERSION 3.1)

project(flush-win-prob)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -Wall -g -DCHECK_HAND")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -Wall")

add_executable(main src/main.cpp)
