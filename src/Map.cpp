#include "Map.h"
#include <cstdlib>
#include <ctime>
#include <iostream>


Map::Map(int rows, int cols, float tileSize) : mRows(rows), mCols(cols), mTileSize(tileSize) {
    mGrid.resize(rows * cols, 0);
}

void Map::generateRandomWalls(int percentage) {
    mSprites.clear();

    for (int i = 0; i < mRows * mCols; ++i) {
        mGrid[i] = (std::rand() % 100 < percentage) ? 1 : 0;

        if ((i+1)%mCols==0)
            std::cout << mGrid[i]<< std::endl;
        else
            std::cout << mGrid[i]<< " ";

        int x = i % mCols;
        int y = i / mCols;

        // Scegliamo la texture corretta
        const sf::Texture& texToUse = (mGrid[i] == 1) ? mWallTex : mGroundTex;

        // Creiamo lo sprite passandogli la texture direttamente (SFML 3 style)
        sf::Sprite sprite(texToUse);

        // Impostiamo la posizione usando le parentesi graffe per il Vector2f
        sprite.setPosition({static_cast<float>(x * mTileSize), static_cast<float>(y * mTileSize)});

        // Aggiungiamo lo sprite al vettore
        mSprites.push_back(sprite);
    }
}

bool Map::loadTextures(const std::string& groundPath, const std::string& wallPath) {
    if (!mGroundTex.loadFromFile(groundPath) || !mWallTex.loadFromFile(wallPath)) {
        return false;
    }
    return true;
}


void Map::draw(sf::RenderWindow& window) {
    for (const auto& sprite : mSprites) {
        window.draw(sprite);
    }
}

int Map::getTileType(int x, int y) const {
    if (x < 0 || x >= mCols || y < 0 || y >= mRows) {
        return -1; // Fuori dai limiti
    }
    return mGrid[y * mCols + x];
}