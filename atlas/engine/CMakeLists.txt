add_executable(Atlas
    src/main.cpp

    engine/app/Application.cpp

    engine/core/Logger.cpp
    engine/core/Timer.cpp

    engine/window/Window.cpp
)

target_include_directories(Atlas
    PRIVATE
        engine
)

target_link_libraries(Atlas
    PRIVATE
        SDL3::SDL3
)