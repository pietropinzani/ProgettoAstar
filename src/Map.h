#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include <vector>

class Map {
public:
    Map(int rows, int cols, float tileSize);
    bool loadTextures(const std::string& groundPath, const std::string& wallPath);
    void generateRandomWalls(int percentage);
    void draw(sf::RenderWindow& window) const;
    int getTileType(int x, int y) const;
    std::vector<int> getGrid() const { return mGrid; }

private:
    int mRows, mCols;
    float mTileSize;
    sf::Texture mGroundTex, mWallTex;
    std::vector<int> mGrid; // 1 terra, 99 muro
    std::vector<sf::Sprite> mSprites;
};

#endif