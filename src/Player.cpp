#include "Player.h"

#include <cmath>

Player::Player(const sf::Texture& texture, float tileSize) 
    : sprite(texture), tileSize(tileSize) {
}

void Player::setGridPosition(int x, int y) {
    gridPos = {x, y};
    sprite.setPosition({x * tileSize, y * tileSize});
}

void Player::draw(sf::RenderWindow& window) const {
    window.draw(sprite);
}

void Player::setPath(const std::vector<sf::Vector2i>& newPath) {
    path = newPath;
    // Rimuoviamo il primo punto perché è la posizione attuale del player
    if (!path.empty()) {
        path.erase(path.begin());
    }
}

void Player::update(float deltaTime) {
    if (path.empty()) return;

    sf::Vector2f targetPos(path[0].x * tileSize, path[0].y * tileSize);
    sf::Vector2f currentPos = sprite.getPosition();

    // Calcoliamo la direzione
    sf::Vector2f direction = targetPos - currentPos;
    float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);

    if (distance < 2.0f) { // Se siamo molto vicini al centro della cella
        sprite.setPosition(targetPos);
        gridPos = path[0];
        path.erase(path.begin()); // Passiamo al prossimo punto
    } else {
        // Movimento fluido verso il target
        sprite.move((direction / distance) * moveSpeed * deltaTime);
    }
}
