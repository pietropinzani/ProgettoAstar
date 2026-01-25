#include <SFML/Graphics.hpp>
#include "Map.h"

int main() {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "A* Pathfinding - Mappa");
    window.setFramerateLimit(60);

    Map gameMap(18, 25, 32.f); // Griglia 25x18 con tile da 32px

    // Assicurati che i file siano in cmake-build-debug/assets/
    if (!gameMap.loadTextures("assets/ground.png", "assets/wall.png")) {
        return -1;
    }

    gameMap.generateRandomWalls(20); // 20% di muri rossi

    while (window.isOpen()) {
        // In SFML 3, pollEvent restituisce un std::optional<sf::Event>
        while (const std::optional event = window.pollEvent()) {

            // Controlliamo il tipo di evento usando il metodo .is<T>()
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }

            // Esempio: Pressione di un tasto (es. 'R' per resettare la mappa)
            if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                if (keyPressed->code == sf::Keyboard::Key::R) {
                    gameMap.generateRandomWalls(20);
                }
            }

            // Esempio: Click del Mouse
            if (const auto* mouseClick = event->getIf<sf::Event::MouseButtonPressed>()) {
                if (mouseClick->button == sf::Mouse::Button::Left) {
                    // Qui gestiremo il target per l'A*
                    int gridX = static_cast<int>(mouseClick->position.x / 32);
                    int gridY = static_cast<int>(mouseClick->position.y / 32);
                }
            }
        }

        window.clear();
        gameMap.draw(window);
        window.display();
    }

    return 0;
}