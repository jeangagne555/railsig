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

FetchContent_Declare(
        SDL3
        GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
        GIT_TAG release-3.2.8
        GIT_SHALLOW TRUE
)
set(SDL_SHARED OFF CACHE BOOL "" FORCE)
set(SDL_STATIC ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(SDL3)

FetchContent_Declare(
        imgui
        GIT_REPOSITORY https://github.com/ocornut/imgui.git
        GIT_TAG v1.91.8-docking
        GIT_SHALLOW TRUE
        SOURCE_SUBDIR ""
)
FetchContent_MakeAvailable(imgui)

add_subdirectory(libs/topology)
add_subdirectory(libs/ui_core)
add_subdirectory(apps/simulator)
add_subdirectory(apps/tester)
