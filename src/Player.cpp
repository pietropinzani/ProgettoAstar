#include "Player.h"
#include <cmath>
#include <iostream>

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

void Player::update(float deltaTime) {
    if (path.empty()) return;

    sf::Vector2f targetPos(path[0].x * tileSize, path[0].y * tileSize);
    sf::Vector2f currentPos = sprite.getPosition();
    sf::Vector2f direction = targetPos - currentPos;

    float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    if (distance < 2.0f) {
        sprite.setPosition(targetPos);
        gridPos = path[0];
        path.erase(path.begin());
    } else
        sprite.move((direction / distance) * moveSpeed * deltaTime);
}
