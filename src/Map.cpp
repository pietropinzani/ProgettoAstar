#include "Map.h"
#include <iostream>


Map::Map(int rows, int cols, float tileSize) : mRows(rows), mCols(cols), mTileSize(tileSize) {
    mGrid.resize(rows * cols, 0);
}

void Map::generateRandomWalls(int percentage) {
    mSprites.clear();

    for (int i = 0; i < mRows * mCols; ++i) {
        mGrid[i] = (std::rand() % 100 < percentage) ? 99 : 1;

        if ((i+1)%mCols==0) {
            if (mGrid[i] == 99)
                std::cout << mGrid[i]<< std::endl;
            else
                std::cout << " " << mGrid[i]<< std::endl;
        }
        else {
            if (mGrid[i] == 99)
                std::cout << mGrid[i]<< " ";
            else
                std::cout << " " << mGrid[i]<< " ";
        }

        int x = i % mCols;
        int y = i / mCols;

        const sf::Texture& texToUse = (mGrid[i] == 99) ? mWallTex : mGroundTex;

        sf::Sprite sprite(texToUse);

        sprite.setPosition({x * mTileSize, y * mTileSize});

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
        return -1;
    }
    return mGrid[y * mCols + x];
}