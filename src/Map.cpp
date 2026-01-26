#include "Map.h"
#include <cstdlib>
#include <ctime>
#include <iostream>


Map::Map(int rows, int cols, float tileSize) : m_rows(rows), m_cols(cols), m_tileSize(tileSize) {
    m_grid.resize(rows * cols, 0);
}

void Map::generateRandomWalls(int percentage) {
    m_sprites.clear();

    for (int i = 0; i < m_rows * m_cols; ++i) {
        m_grid[i] = (std::rand() % 100 < percentage) ? 1 : 0;

        if ((i+1)%25==0)
            std::cout << m_grid[i]<< std::endl;
        else
            std::cout << m_grid[i]<< " ";

        int x = i % m_cols;
        int y = i / m_cols;

        // Scegliamo la texture corretta
        const sf::Texture& texToUse = (m_grid[i] == 1) ? m_wallTex : m_groundTex;

        // Creiamo lo sprite passandogli la texture direttamente (SFML 3 style)
        sf::Sprite sprite(texToUse);

        // Impostiamo la posizione usando le parentesi graffe per il Vector2f
        sprite.setPosition({static_cast<float>(x * m_tileSize), static_cast<float>(y * m_tileSize)});

        // Aggiungiamo lo sprite al vettore
        m_sprites.push_back(sprite);
    }
}

bool Map::loadTextures(const std::string& groundPath, const std::string& wallPath) {
    if (!m_groundTex.loadFromFile(groundPath) || !m_wallTex.loadFromFile(wallPath)) {
        return false;
    }
    return true;
}


void Map::draw(sf::RenderWindow& window) {
    for (const auto& sprite : m_sprites) {
        window.draw(sprite);
    }
}

int Map::getTileType(int x, int y) const {
    if (x < 0 || x >= m_cols || y < 0 || y >= m_rows) {
        return -1; // Fuori dai limiti
    }
    return m_grid[y * m_cols + x];
}