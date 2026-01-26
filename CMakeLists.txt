cmake_minimum_required(VERSION 3.28) # Nota: la 4.1 non esiste ancora stabilmente, meglio usare 3.28+
project(ProgettoAStar LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Scarica SFML
include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.0 # Versione stabile release
        GIT_SHALLOW ON
        SYSTEM)
FetchContent_MakeAvailable(SFML)

# 2. Definisci i file del progetto
# Nota: includiamo i file .h così CLion li mostra nell'albero del progetto
set(SOURCES
        src/main.cpp
        src/Astar.cpp
        src/fsa.h
        src/stlastar.h
        src/Map.cpp
        src/Map.h
        src/Player.cpp
        src/Player.h
)

# 3. Crea l'eseguibile usando il nome del Progetto
add_executable(ProgettoAStar ${SOURCES})

# 4. Collega le librerie al target corretto
target_link_libraries(ProgettoAStar PRIVATE SFML::Graphics)

# 5. Copia gli asset nella cartella di build
file(COPY assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})