cmake_minimum_required(VERSION 3.25)
project(railsig VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(RAILSIG_BUILD_TESTS "Build unit tests for railsig libraries" ON)

if(RAILSIG_BUILD_TESTS)
    include(FetchContent)
    FetchContent_Declare(
            Catch2
            GIT_REPOSITORY https://github.com/catchorg/Catch2.git
            GIT_TAG v3.7.1
    )
    FetchContent_MakeAvailable(Catch2)
    enable_testing()
endif()

add_subdirectory(libs/topology)
add_subdirectory(apps/simulator)
