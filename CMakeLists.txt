cmake_minimum_required(VERSION 3.20)
project(myproj LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)          # -std=c++20, not gnu++20
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)  # for clangd

add_executable(compiler
    src/main.cpp
    src/Position.cpp
    src/Scanner.cpp
    src/Source.cpp
    src/Token.cpp
)
target_include_directories(compiler PRIVATE include)
target_compile_options(compiler PRIVATE -Wall -Wextra -Wpedantic)
