cmake_minimum_required(VERSION 3.28)
project(gettisXX)

set(CMAKE_CXX_STANDARD 11)  # Adjust as per your requirement, C++11 or later recommended

# Locate Curl package
find_package(CURL REQUIRED)

# Add executable and link with Curl
add_executable(gettisXX
        src/main.cpp
        src/Language.cpp
        src/Language.h
        src/InterpretedLanguage.cpp
        src/InterpretedLanguage.h
        src/CompiledLanguage.cpp
        src/CompiledLanguage.h
        src/fetcher.cpp
        src/fetcher.h
)

target_link_libraries(gettisXX CURL::libcurl)
