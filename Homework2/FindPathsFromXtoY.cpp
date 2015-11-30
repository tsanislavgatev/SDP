#include "FindPathsFromXtoY.h"
#include <iostream>

FindPathsFromXtoY::FindPathsFromXtoY()
{
    fillMoves();
    vectorIndex = 0;
}

FindPathsFromXtoY::FindPathsFromXtoY(Maze& mazeT, Cell* start, Cell* finalC)
{
    this -> mazeTable = mazeT;
    this -> startCell = start;
    this -> finalCell = finalC;
    fillMoves();
    vectorIndex = 0;
    findAllThePaths(mazeT,start,finalC);
}

void FindPathsFromXtoY::fillMoves()
{
    xMoves[0] = 0;
    xMoves[1] = -1; // down
    xMoves[2] = 0;
    xMoves[3] = 1; // up
    yMoves[0] = -1; // left
    yMoves[1] = 0;
    yMoves[2] = 1; // right
    yMoves[3] = 0;
}

void FindPathsFromXtoY::findAllThePaths(Maze& mazeT, Cell* startC, Cell* finalC)
{
	currentPath.pathVec.push_back(startC);
	currentPath.sizeOfPath++;
	startC->isCovered = true;

    if(startC->row == finalC->row &&
       startC->col == finalC->col)
    {
        allThePaths.push_back(currentPath);

        /*std::cout << "Current situation: " << std::endl;
        printAllThePaths();*/

        // currentPath.clear();
        // currentPath.pathVec.push_back(startCell);

        return;
    }



    for(int i = 0; i < 4; i++)
    {
        if(startC->row + xMoves[i] >= 0 &&
           startC->row + xMoves[i] < mazeT.getRows() &&
           startC->col + yMoves[i] >=0 &&
           startC->col + yMoves[i] < mazeT.getCols())
        {
            Cell* stepCell = mazeT.getCell(startC->row + xMoves[i], startC->col + yMoves[i]);
            if(stepCell &&
			   stepCell->isCovered == false &&
               stepCell->isOkayToPass())
            {
                // currentPath.push_back(stepCell);
                findAllThePaths(mazeT,stepCell,finalC);

				currentPath.pathVec.pop_back();
				currentPath.sizeOfPath--;
				stepCell->isCovered = false;
            }
        }
    }

    // startC->isCovered = false;
}

void FindPathsFromXtoY::printAllThePaths()
{
    if(allThePaths.size() > 1)
    {
        sortThePaths();
    }
    std::cout << "\n(" << finalCell->row << " . " << finalCell->col << ")";
    for(int i = 0; i < allThePaths.size(); i++)
    {
        std::cout <<"\n";
        for(int j = 0; j < allThePaths[i].sizeOfPath; j++)
        {
            std::cout << "(" << allThePaths[i].pathVec[j]->row << " . " << allThePaths[i].pathVec[j]->col << ")";
        }

    }
}

void FindPathsFromXtoY::sortThePaths()
{
    int j = 0;
    path temp;
    for(int i = 0; i < allThePaths.size(); ++i)
    {
        j = i;
        while( (j > 0) &&
              allThePaths[j].sizeOfPath < allThePaths[j - 1].sizeOfPath)
        {
            temp = allThePaths[j];
            allThePaths[j] = allThePaths[j - 1];
            allThePaths[j - 1] = temp;
            j--;
        }
    }
}
