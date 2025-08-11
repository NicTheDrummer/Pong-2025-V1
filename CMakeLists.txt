cmake_minimum_required(VERSION 3.31)
project(Pong)

include(FetchContent)
set(BUILD_SHARED_LIBS OFF)

FETCHCONTENT_DECLARE(SFML GIT_REPOSITORY https://github.com/SFML/SFML.git GIT_TAG 3.0.0)
FETCHCONTENT_MAKEAVAILABLE(SFML)

set(CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

add_executable(Pong src/main.cpp
        src/GamePanel.cpp
        headers/GamePanel.h
        src/Player.cpp
        headers/Player.h
        src/Ball.cpp
        headers/Ball.h
)

target_link_libraries(Pong sfml-graphics)