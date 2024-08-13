cmake_minimum_required(VERSION 3.28)
project(gettisXX)

set(CMAKE_CXX_STANDARD 17)  # Adjust as per your requirement, C++11 or later recommended

# Include FetchContent module
include(FetchContent)

# Locate OpenSSL package
find_package(OpenSSL QUIET)

# If OpenSSL is not found, fetch and build it
if(NOT OpenSSL_FOUND)
    message(STATUS "OpenSSL not found, fetching it...")

    FetchContent_Declare(
            openssl
            URL https://www.openssl.org/source/openssl-3.0.14.tar.gz
            URL_HASH SHA256=eeca035d4dd4e84fc25846d952da6297484afa0650a6f84c682e39df3a4123ca
    )

    FetchContent_MakeAvailable(openssl)

    # Set OpenSSL root directory
    set(OPENSSL_ROOT_DIR ${openssl_SOURCE_DIR})
    set(OPENSSL_INCLUDE_DIR ${openssl_SOURCE_DIR}/include)
    set(OPENSSL_CRYPTO_LIBRARY ${openssl_BINARY_DIR}/libcrypto.a)
    set(OPENSSL_SSL_LIBRARY ${openssl_BINARY_DIR}/libssl.a)

    # Manually define OpenSSL targets
    add_library(OpenSSL::Crypto UNKNOWN IMPORTED)
    set_target_properties(OpenSSL::Crypto PROPERTIES
            IMPORTED_LOCATION ${OPENSSL_CRYPTO_LIBRARY}
            INTERFACE_INCLUDE_DIRECTORIES ${OPENSSL_INCLUDE_DIR}
    )

    add_library(OpenSSL::SSL UNKNOWN IMPORTED)
    set_target_properties(OpenSSL::SSL PROPERTIES
            IMPORTED_LOCATION ${OPENSSL_SSL_LIBRARY}
            INTERFACE_INCLUDE_DIRECTORIES ${OPENSSL_INCLUDE_DIR}
    )

    # Find OpenSSL again after building it
    find_package(OpenSSL REQUIRED)
endif()

# Locate Curl package
find_package(CURL QUIET)

# If CURL is not found, fetch and build it
if(NOT CURL_FOUND)
    message(STATUS "CURL not found, fetching it...")

    FetchContent_Declare(
            curl
            URL https://curl.se/download/curl-8.8.0.tar.gz
            URL_HASH SHA256=77c0e1cd35ab5b45b659645a93b46d660224d0024f1185e8a95cdb27ae3d787d
    )

    # Set CMake options for building curl with static library and OpenSSL
    set(CURL_USE_OPENSSL TRUE)
    set(BUILD_CURL_EXE OFF)
    set(BUILD_SHARED_LIBS OFF)
    set(CURL_STATICLIB ON)
    set(OPENSSL_ROOT_DIR ${OPENSSL_ROOT_DIR})
    set(OPENSSL_INCLUDE_DIR ${OPENSSL_INCLUDE_DIR})
    set(OPENSSL_CRYPTO_LIBRARY ${OPENSSL_CRYPTO_LIBRARY})
    set(OPENSSL_SSL_LIBRARY ${OPENSSL_SSL_LIBRARY})

    FetchContent_MakeAvailable(curl)

    # Set CURL root directory
    set(CURL_ROOT ${curl_SOURCE_DIR})
    set(CURL_INCLUDE_DIR ${curl_SOURCE_DIR}/include)
    set(CURL_LIBRARY ${curl_BINARY_DIR}/lib/libcurl.a)

    # Find CURL again after building it
    find_package(CURL REQUIRED)
endif()

FetchContent_Declare(
        tomlplusplus
        GIT_REPOSITORY https://github.com/marzer/tomlplusplus.git
        GIT_TAG v3.4.0
)
FetchContent_MakeAvailable(tomlplusplus)

# Add executable and link with Curl and OpenSSL
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
        src/langs/Java.cpp
        src/langs/Java.h
        src/ProjectSettings.cpp
        src/ProjectSettings.h
)

# Include directories for CURL and tomlplusplus
target_include_directories(gettisXX PRIVATE ${CURL_INCLUDE_DIR} ${tomlplusplus_SOURCE_DIR}/include)

# Link with the appropriate libraries
target_link_libraries(gettisXX PRIVATE ${CURL_LIBRARY} OpenSSL::SSL OpenSSL::Crypto)
