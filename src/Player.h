#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class Player {
public:
    Player(const sf::Texture& texture, float tileSize);
    
    void setGridPosition(int x, int y);
    sf::Vector2i getGridPosition() const { return gridPos; }
    void draw(sf::RenderWindow& window) const;
    void setPath(const std::vector<sf::Vector2i>& newPath){path = newPath;}
    void update(float deltaTime);
    bool isMoving() const { return !path.empty(); }

private:
    sf::Sprite sprite;
    sf::Vector2i gridPos; // Posizione attuale sulla griglia (es. 0,0)
    float tileSize;
    std::vector<sf::Vector2i> path; // La coda dei passi da fare
    float moveSpeed = 200.0f;
};

#endif