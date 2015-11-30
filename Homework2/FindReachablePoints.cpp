#include "FindReachablePoints.h"
#include <iostream>

FindReachablePoints::FindReachablePoints()
{

}

FindReachablePoints::FindReachablePoints(Maze maze,size_t r, size_t c)
{
    this -> startCell = new Cell;
    this -> mazeTable = maze;
    startCell -> row = r;
    startCell -> col = c;
    mazeTable.getMaze()[r][c].isCovered = true;
}

FindReachablePoints::~FindReachablePoints()
{
    delete startCell;
}

void FindReachablePoints::BFS()
{
    if(!mazeTable.getMaze()[startCell->row][startCell->col].isOkayToPass())
    {
        std::cout << "\nYou are in blocked cell !" << std::endl;
    }
    else
    {
        Queue<Cell*> que;
        que.enqueue(startCell);
        while(!que.isEmpty())
        {
            Cell* currentCell = que.frontElement();
            //currentCell -> isCovered = true;
            que.dequeue();
            addIfPossible(que, mazeTable.getOneLeft(currentCell));
            addIfPossible(que, mazeTable.getOneRight(currentCell));
            addIfPossible(que, mazeTable.getOneUp(currentCell));
            addIfPossible(que, mazeTable.getOneDown(currentCell));
        }
	}
}

void FindReachablePoints::addIfPossible(Queue<Cell*>& q, Cell* cellForAdd)
{
    if(cellForAdd &&
       cellForAdd-> isCovered == false &&
       cellForAdd -> isOkayToPass())
    {
        cellForAdd -> isCovered = true;
        reachablePoints.push_back(cellForAdd);
        //std::cout << "\n" << cellForAdd -> row << " . " << cellForAdd -> col << std::endl;
        q.enqueue(cellForAdd);
    }
}

std::vector<Cell*> FindReachablePoints::getVector()
{
    return reachablePoints;
}
