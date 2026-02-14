cmake_minimum_required(VERSION 3.28)
project(ProgettoAStar LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.0
        GIT_SHALLOW ON
        SYSTEM)
FetchContent_MakeAvailable(SFML)

set(SOURCES
        src/main.cpp
        src/Astar.cpp
        src/fsa.h
        src/stlastar.h
        src/Map.cpp
        src/Map.h
        src/Player.cpp
        src/Player.h
        src/MapSearchNode.cpp
        src/MapSearchNode.h
)

add_executable(ProgettoAStar ${SOURCES})

target_link_libraries(ProgettoAStar PRIVATE SFML::Graphics)

file(COPY assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})