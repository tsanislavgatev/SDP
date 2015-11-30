#pragma once
#include <iostream>

struct Cell{
    size_t row;
    size_t col;

    char symbol;

    bool isCovered;

    bool isOkayToPass()
    {
        if(symbol == '.')
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    Cell(size_t r, size_t c)
    {
        row = r;
        col = c;
        isCovered = false;
    }

    Cell()
    {
        isCovered = false;
    }

};

class Maze
{
    private:
        size_t columns;
        size_t rows;

        Cell** mazeTable;

    public:
        Maze(size_t, size_t);
        Maze();
        ~Maze();
        Maze(const Maze& other);
        Maze& operator=(const Maze& other);

    private:
        void fillTheMaze();
        void takeValues(size_t, size_t);
        void copyMaze(const Maze& other);
        void destroyMaze();


    public:
        void printTheTable();
        void makeAllNotCovered();

        Cell* getCell(size_t, size_t);
        Cell** getMaze() const;
        size_t getRows() const;
        size_t getCols() const;

        Cell* getOneUp(Cell*);
        Cell* getOneDown(Cell*);
        Cell* getOneLeft(Cell*);
        Cell* getOneRight(Cell*);
};

