add_executable(learning
    src/main.cpp
    src/player.cpp
    src/chrono.cpp
)

target_include_directories(learning
PRIVATE
    include
)