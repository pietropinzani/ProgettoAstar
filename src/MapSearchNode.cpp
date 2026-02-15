#include "MapSearchNode.h"

Map* MapSearchNode::gameMap = nullptr;

    bool MapSearchNode::IsSameState(MapSearchNode& rhs) const {
        // same state in a maze search is simply when (x,y) are the same
        if ((x == rhs.x) && (y == rhs.y)) {
            return true;
        } else {
            return false;
        }
    }

    size_t MapSearchNode::Hash() const {
        size_t h1 = hash<float>{}(x);
        size_t h2 = hash<float>{}(y);
        return h1 ^ (h2 << 1);
    }

    void MapSearchNode::PrintNodeInfo() const {
        const int strSize = 100;
        char str[strSize];
        snprintf(str, strSize, "Node position : (%d,%d)\n", x, y);

        cout << str;
    }

    float MapSearchNode::GoalDistanceEstimate(MapSearchNode& nodeGoal) const {
        return abs(x - nodeGoal.x) + abs(y - nodeGoal.y);
    }

    bool MapSearchNode::IsGoal(MapSearchNode& nodeGoal) const {
        if ((x == nodeGoal.x) && (y == nodeGoal.y)) {
            return true;
        }

        return false;
    }


    bool MapSearchNode::GetSuccessors(AStarSearch<MapSearchNode>* astarsearch, MapSearchNode* parent_node) const {
        int parent_x = -1;
        int parent_y = -1;

        if (parent_node) {
            parent_x = parent_node->x;
            parent_y = parent_node->y;
        }

        MapSearchNode NewNode;

        if (x > 0 && (gameMap->getTileType(x - 1, y) < 99) && !((parent_x == x - 1) && (parent_y == y))) {
            NewNode = MapSearchNode(x - 1, y);
            astarsearch->AddSuccessor(NewNode);
        }

        if (y > 0 && (gameMap->getTileType(x, y - 1) < 99) && !((parent_x == x) && (parent_y == y - 1))) {
            NewNode = MapSearchNode(x, y - 1);
            astarsearch->AddSuccessor(NewNode);
        }

        if (x < 24 && (gameMap->getTileType(x + 1, y) < 99) && !((parent_x == x + 1) && (parent_y == y))) {
            NewNode = MapSearchNode(x + 1, y);
            astarsearch->AddSuccessor(NewNode);
        }

        if (y < 17 && (gameMap->getTileType(x, y + 1) < 99) && !((parent_x == x) && (parent_y == y + 1))) {
            NewNode = MapSearchNode(x, y + 1);
            astarsearch->AddSuccessor(NewNode);
        }

        return true;
    }

    float MapSearchNode::GetCost(MapSearchNode& successor) const {
        return static_cast<float>(gameMap->getTileType(x, y));
    }


