//
// Created by Pietro Pinzani on 03/02/26.
//

#ifndef MAPSEARCHNODE_H
#define MAPSEARCHNODE_H

#include <math.h>
#include "stlastar.h"
#include "Map.h"
using namespace std;


class MapSearchNode {
   public:
    int x;  // the (x,y) positions of the node
    int y;
    static Map* gameMap;

    MapSearchNode() {
        x = y = 0;
    }

    MapSearchNode(int px, int py) {
        x = px;
        y = py;
    }

    float GoalDistanceEstimate(MapSearchNode& nodeGoal) const;
    bool IsGoal(MapSearchNode& nodeGoal) const;
    bool GetSuccessors(AStarSearch<MapSearchNode>* astarsearch, MapSearchNode* parent_node) const;
    float GetCost(MapSearchNode& successor) const;
    bool IsSameState(MapSearchNode& rhs) const;
    size_t Hash() const;

    void PrintNodeInfo() const;
};

#endif