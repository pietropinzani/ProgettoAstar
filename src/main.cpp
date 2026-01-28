#include <SFML/Graphics.hpp>
#include <iostream>
#include "Map.h"
#include "Player.h"

int main() {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "A* Pathfinding - Mappa");
    window.setFramerateLimit(60);
    int rows=18,cols=25;
    Map gameMap(rows, cols, 32.f);
    if (!gameMap.loadTextures("assets/ground.png", "assets/wall.png"))
        return -1;
    gameMap.generateRandomWalls(20); // 20% di muri

    sf::Texture playerTex;
    if (!playerTex.loadFromFile("assets/player.png"))
        return -1;
    Player player(playerTex, 32.f);

    int x=0, y=0;
    while (gameMap.getTileType(x,y)==1) {
        x++;
        if (x>=cols) {
            x=0;
            y++;
        }
    }

    player.setGridPosition(x, y);

    sf::Vector2i targetPos = player.getGridPosition();
    bool hasTarget = false;


    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {

            if (event->is<sf::Event::Closed>()) {
                window.close();
            }

            if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                if (keyPressed->code == sf::Keyboard::Key::R) {
                    gameMap.generateRandomWalls(20);
                }
                if (keyPressed->code == sf::Keyboard::Key::Left) {
                    sf::Vector2i pos = player.getGridPosition();
                    if (gameMap.getTileType(pos.x - 1, pos.y) == 0)
                        player.setGridPosition(pos.x - 1, pos.y);
                }
                if (keyPressed->code == sf::Keyboard::Key::Right) {
                    sf::Vector2i pos = player.getGridPosition();
                    if (gameMap.getTileType(pos.x + 1, pos.y) == 0)
                        player.setGridPosition(pos.x + 1, pos.y);
                }
                if (keyPressed->code == sf::Keyboard::Key::Up) {
                    sf::Vector2i pos = player.getGridPosition();
                    if (gameMap.getTileType(pos.x, pos.y - 1) == 0)
                        player.setGridPosition(pos.x, pos.y - 1);
                }
                if (keyPressed->code == sf::Keyboard::Key::Down) {
                    sf::Vector2i pos = player.getGridPosition();
                    if (gameMap.getTileType(pos.x, pos.y + 1) == 0)
                        player.setGridPosition(pos.x, pos.y + 1);
                }
            }



            if (const auto* mouseClick = event->getIf<sf::Event::MouseButtonPressed>()) {
                if (mouseClick->button == sf::Mouse::Button::Left) {
                    int gridX = static_cast<int>(mouseClick->position.x / 32);
                    int gridY = static_cast<int>(mouseClick->position.y / 32);

                    if (gridX >= 0 && gridX < cols && gridY >= 0 && gridY < rows) {
                        if (gameMap.getTileType(gridX, gridY) == 0) {
                            targetPos = {gridX, gridY};
                            hasTarget = true;
                            std::cout << "Nuovo target impostato: " << gridX << ", " << gridY << std::endl;
                        } else
                            std::cout << "Punto non raggiungibile (muro)!" << std::endl;
                    }
                }
            }
            window.clear();
            gameMap.draw(window);
            player.draw(window);
            window.display();
        }
    }
    return 0;
}