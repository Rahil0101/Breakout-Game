cmake_minimum_required(VERSION 3.28)

project(Breakout LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 3 COMPONENTS Graphics Window System REQUIRED)

add_executable(Breakout
    src/main.cpp
    include/Game.hpp
    include/Ball.hpp
    src/Ball.cpp
    src/Game.cpp
    src/LoadAssets.cpp
    src/Paddle.cpp
    src/Brick.cpp
    include/LevelConfig.hpp
)

target_link_libraries(Breakout PRIVATE
    SFML::Graphics
    SFML::Window
    SFML::System
)