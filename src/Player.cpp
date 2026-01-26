#include "Player.h"

Player::Player(const sf::Texture& texture, float tileSize) 
    : m_sprite(texture), m_tileSize(tileSize) {
}

void Player::setGridPosition(int x, int y) {
    m_gridPos = {x, y};
    m_sprite.setPosition({x * m_tileSize, y * m_tileSize});
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(m_sprite);
}