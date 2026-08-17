add_library(Engine
    app/Application.cpp

    core/Logger.cpp
    core/Timer.cpp

    window/Window.cpp
)

target_include_directories(Engine
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(Engine
    PUBLIC
        SDL3::SDL3
)