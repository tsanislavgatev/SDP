#pragma once

#include "Maze.h"
#include <vector>

struct path{
    std::vector<Cell*> pathVec;
    int sizeOfPath;
    path()
    {
        sizeOfPath = 0;
    }
    path(const path& other)
    {
        pathVec = other.pathVec;
        sizeOfPath = other.sizeOfPath;
    }
};

class FindPathsFromXtoY
{
    public:
        FindPathsFromXtoY();
        FindPathsFromXtoY(Maze&, Cell*, Cell*);

    private:
        Maze mazeTable;
        Cell* startCell;
        Cell* finalCell;

        int xMoves[4];
        int yMoves[4];
        int vectorIndex;

        std::vector<path> allThePaths;
        path currentPath;
    public:
        void findAllThePaths(Maze& mazeT, Cell* startC, Cell* finalC);
        void printAllThePaths();

    private:
        void fillMoves();
        void sortThePaths();
};


