#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include <vector>

class Map {
public:
    Map(int rows, int cols, float tileSize);
    bool loadTextures(const std::string& groundPath, const std::string& wallPath);
    void generateRandomWalls(int percentage);
    void draw(sf::RenderWindow& window);
    // Utile per A* in futuro
    int getTileType(int x, int y) const;

private:
    int m_rows, m_cols;
    float m_tileSize;
    sf::Texture m_groundTex, m_wallTex;
    std::vector<int> m_grid; // 0: terra, 1: muro
    std::vector<sf::Sprite> m_sprites;
};

#endif