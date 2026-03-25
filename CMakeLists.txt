cmake_minimum_required(VERSION 3.16)

project(PongAI LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

add_executable(PongAI
  main.cpp
  game/Paddle.cpp
  game/Ball.cpp
  game/Arena.cpp
  neural/Layer.cpp
  neural/NeuralNetwork.cpp
  agent/Agent.cpp
)

find_package(SFML 3 COMPONENTS Graphics REQUIRED)

target_link_libraries(PongAI PRIVATE SFML::Graphics)
