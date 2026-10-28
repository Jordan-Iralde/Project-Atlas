cmake_minimum_required(VERSION 3.20)

project(Atlas
    VERSION 0.1.0
    LANGUAGES CXX
)

include(FetchContent)

FetchContent_Declare(
    SDL3
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG        main
)

FetchContent_MakeAvailable(SDL3)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(engine)
