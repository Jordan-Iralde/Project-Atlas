add_executable(Atlas
    src/main.cpp
    src/Application.cpp
    src/Logger.cpp
    src/Window.cpp
    src/Timer.cpp)

target_compile_options(Atlas
    PRIVATE
        -Wall
        -Wextra
        -Wpedantic
)

target_link_libraries(Atlas
    PRIVATE
        SDL3::SDL3
)

target_include_directories(Atlas
PRIVATE
    include
)
