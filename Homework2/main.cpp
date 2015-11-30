#include <iostream>
#include "Maze.h"
#include "FindReachablePoints.h"
#include <vector>
#include "FindPathsFromXtoY.h"

using namespace std;

int main()
{
    size_t rows, cols;
    std::cout << "Enter count of rows : ";
    std::cin >> rows;
    std::cout << "\nEnter count of columns : ";
    std::cin >> cols;
    Maze test(rows,cols);
    test.printTheTable();
    size_t x, y;
    std::cout << "\nEnter row for starting point : ";
    std::cin >> x;
    std::cout << "\nEnter column for starting point : ";
    std::cin >> y;
    FindReachablePoints findTheCells(test,x,y);
    findTheCells.BFS();
    std::vector<Cell*> newVec = findTheCells.getVector();
    std::cout << "The reachable points are : "<<std::endl;
    for(int i = 0; i < newVec.size() ; i++)
    {
        std::cout << "(" << newVec[i] -> row << " . " << newVec[i] -> col << ") ";
    }
    Cell* startCell = &test.getMaze()[x][y];
    std::cout << "\nAll the paths to all the cells are : " << std::endl;
    for(int i = 0; i < newVec.size();i++)
    {
        FindPathsFromXtoY findPath(test,startCell,newVec[i]);
        findPath.printAllThePaths();
    }

    return 0;
}
