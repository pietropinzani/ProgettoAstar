#include "Player.h"

Player::Player(const sf::Texture& texture, float tileSize) 
    : sprite(texture), tileSize(tileSize) {
}

void Player::setGridPosition(int x, int y) {
    gridPos = {x, y};
    sprite.setPosition({x * tileSize, y * tileSize});
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}