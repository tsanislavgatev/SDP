#pragma once

#include "Maze.h"
#include <vector>
#include "Queue.h"

class FindReachablePoints
{
    public:
        FindReachablePoints();
        FindReachablePoints(Maze ,size_t, size_t);
        ~FindReachablePoints();

    private:
        Maze mazeTable;
        Cell* startCell;
        std::vector<Cell*> reachablePoints;

    public:
        void BFS();
        std::vector<Cell*> getVector();

    private:
        void addIfPossible(Queue<Cell*>&, Cell*);
};


