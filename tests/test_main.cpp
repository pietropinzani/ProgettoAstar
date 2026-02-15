#include <gtest/gtest.h>
#include "../src/Map.h"
#include "../src/Player.h"
#include "../src/MapSearchNode.h"


TEST(MapTest, TileGeneration) {
    Map m(10, 20, 32.0f);
    m.generateRandomWalls(100);
    for (int y = 0; y < 10; ++y) {
        for (int x = 0; x < 20; ++x)
            EXPECT_EQ(m.getTileType(x, y), 99);
    }

    m.generateRandomWalls(0);
    for (int y = 0; y < 10; ++y) {
        for (int x = 0; x < 20; ++x)
            EXPECT_EQ(m.getTileType(x, y), 1);
    }
}

TEST(PlayerTest, PathFollowing) {
    sf::Texture dummyTex;
    Player p(dummyTex, 32.0f);
    p.setGridPosition(0, 0);

    std::vector<sf::Vector2i> testPath = {{0, 0}, {1, 0}};
    p.setPath(testPath);

    while(p.isMoving()) {
        p.update(0.016f);
    }
    EXPECT_EQ(p.getGridPosition().x, 1);
}

TEST(IntegrationTest, SearchNodeConsistency) {
    Map m(10, 10, 32.0f);
    MapSearchNode::gameMap = &m;

    MapSearchNode node(5, 5);
    EXPECT_EQ(MapSearchNode::gameMap->getTileType(5, 5), m.getTileType(5, 5));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}