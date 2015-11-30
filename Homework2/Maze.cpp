#include "Maze.h"
#include <iostream>

Maze::Maze()
{
    mazeTable = NULL;
    columns = 0;
    rows = 0;
}

Maze::Maze(size_t r,size_t c)
{
    mazeTable = new Cell*[r];
    for(int i = 0; i < r; i++)
    {
        mazeTable[i] = new Cell[c];
    }
    takeValues(r,c);
    fillTheMaze();
}

Maze::~Maze()
{
    for(int i = 0; i < rows; i++)
    {
        delete[] mazeTable[i];
    }
    delete[] mazeTable;
}

Maze::Maze(const Maze& other)
{
    this -> copyMaze(other);
}

Maze& Maze::operator=(const Maze& other)
{
    if(this == &other) return *this;
    else
    {
        this -> destroyMaze();
        this -> copyMaze(other);

        return *this;
    }
}

void Maze::copyMaze(const Maze& other)
{
    this -> rows = other.getRows();
    this -> columns = other.getCols();

    mazeTable = new Cell*[rows];

    for(int i = 0; i < rows; i++)
    {
        this -> mazeTable[i] = new Cell[columns];
        for(int j = 0; j < columns; j++)
        {
            this -> mazeTable[i][j] = other.getMaze()[i][j];
        }
    }
}

void Maze::destroyMaze()
{
    for(int i = 0; i < rows; i++)
    {
        delete[] mazeTable[i];
    }
    delete[] mazeTable;
}

size_t Maze::getRows() const
{
    return rows;
}

size_t Maze::getCols() const
{
    return columns;
}

void Maze::fillTheMaze()
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            std::cout << "Enter a symbol on row "
                      << i + 1
                      << " and col "
                      << j + 1 << std::endl;
            do{
                std::cout << "Enter a '.' for a free cell, and '#' for a blocked cell : ";
                std::cin >> mazeTable[i][j].symbol;
            }while(mazeTable[i][j].symbol != '.' && mazeTable[i][j].symbol != '#');
            mazeTable[i][j].row = i;
            mazeTable[i][j].col = j;
        }
    }
}

void Maze::takeValues(size_t r, size_t c)
{
    this -> rows = r;
    this -> columns = c;
}

void Maze::printTheTable()
{
    std::cout << "\n";
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
                std::cout << mazeTable[i][j].symbol;
        }
        std::cout << "\n";
    }
}

Cell** Maze::getMaze() const
{
    return mazeTable;
}

void Maze::makeAllNotCovered()
{
	for(int row = 0; row < rows; row++)
	{
		for(int col = 0; col < columns; col++)
		{
			mazeTable[row][col].isCovered = false;
		}
	}
}

Cell* Maze::getCell(size_t row, size_t col)
{
    // rows и columns не са валидни индекси в масива, затова ги слагаме в първия if
	if(	row < 0 ||
        row >= rows ||
		col < 0 ||
		col >= columns)
	{
		return NULL;
	}
    if(mazeTable[row][col].symbol == '#')
    {
        return NULL;
    }
    return &mazeTable[row][col];
}

Cell* Maze::getOneUp(Cell* temp)
{
    size_t tempRow = temp -> row;
    size_t tempCol = temp -> col;

    return getCell(tempRow + 1,tempCol);
}

Cell* Maze::getOneDown(Cell* temp)
{
    size_t tempRow = temp -> row;
    size_t tempCol = temp -> col;

    return getCell(tempRow - 1, tempCol);
}

Cell* Maze::getOneLeft(Cell* temp)
{
    size_t tempRow = temp -> row;
    size_t tempCol = temp -> col;

    return getCell(tempRow,tempCol - 1);
}

Cell* Maze::getOneRight(Cell* temp)
{
    size_t tempRow = temp -> row;
    size_t tempCol = temp -> col;

    return getCell(tempRow, tempCol + 1);
}
