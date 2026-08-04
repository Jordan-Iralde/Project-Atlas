add_executable(Atlas
    src/main.cpp
    src/Application.cpp
    src/Logger.cpp
    src/Window.cpp
    src/Timer.cpp)

target_include_directories(Atlas
PRIVATE
    include
)