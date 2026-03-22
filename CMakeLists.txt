cmake_minimum_required(VERSION 3.16)

project(PongAI LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(PongAI
  game/main.cpp
  game/Paddle.cpp
  game/Ball.cpp
  game/Arena.cpp
)

find_package(SFML 3 COMPONENTS Graphics REQUIRED)

target_link_libraries(PongAI PRIVATE SFML::Graphics)
