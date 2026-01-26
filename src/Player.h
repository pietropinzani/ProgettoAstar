#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class Player {
public:
    Player(const sf::Texture& texture, float tileSize);
    
    void setGridPosition(int x, int y);
    sf::Vector2i getGridPosition() const { return m_gridPos; }
    void draw(sf::RenderWindow& window);

private:
    sf::Sprite m_sprite;
    sf::Vector2i m_gridPos; // Posizione attuale sulla griglia (es. 0,0)
    float m_tileSize;
};

#endif