cmake_minimum_required(VERSION 3.28)
project(gettisXX)

set(CMAKE_CXX_STANDARD 26)

add_executable(gettisXX src/main.cpp
        src/Language.cpp
        src/Language.h
        src/Interpreted.cpp
        src/Interpreted.h
        src/Compiled.cpp
        src/Compiled.h
)
