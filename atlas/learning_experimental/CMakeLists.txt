add_executable(learning_experimental
    src/main.cpp
    src/player.cpp
    "src/testtimerlearn.cpp"
)

target_include_directories(learning_experimental
PRIVATE
    include
)