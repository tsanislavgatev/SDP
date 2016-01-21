#include "convertFileToDataMatrix.h"

convertFileToDataMatrix::convertFileToDataMatrix()
{
    this->columns = 1;
    this->rows = 0;
    this->nameOfFile = NULL;
    matrixWithNumbers = NULL;
    this->countOfPeople = 0;
    this->countOfPlaces = 0;
}

convertFileToDataMatrix::~convertFileToDataMatrix()
{
    delete[] nameOfFile;
    for(size_t i = 0; i < this -> rows;i++)
    {
        delete[] matrixWithNumbers[i];
    }
    delete[] matrixWithNumbers;
}

convertFileToDataMatrix::convertFileToDataMatrix(const convertFileToDataMatrix& other)
{
    //copy ctor
}

convertFileToDataMatrix& convertFileToDataMatrix::operator=(const convertFileToDataMatrix& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

void convertFileToDataMatrix::setNameOfFile(char* name)
{
    size_t length = strlen(name)+1;
    this->nameOfFile = new char[length];
    strcpy(this->nameOfFile,name);
}

void convertFileToDataMatrix::readTheFile()
{
    std::ifstream classFile(nameOfFile);
    std::vector<std::vector<std::string> > bigDataFile;
    std::string line;

    std::string row;
    getline(classFile,row);

    size_t p  = 0;
    while(row[p])
    {
        if(row[p] == ',')
        {
            this->columns++;
        }
        p++;
    }

    int wordTaker = 0;
    std::string tempWord;
    for(size_t i = 1; i < row.size(); i++)
    {
        if(row[i] == ',' || i == row.size()-1)
        {
            wordTaker = 0;
            namesOfPlaces.push_back(tempWord);
            tempWord.clear();
            i++;
        }
        tempWord.append(1,row[i]);
        wordTaker++;
    }

    while(!classFile.eof())
    {
        size_t newLiner = 0;
        std::vector<std::string> classData;
        std::string word;

        while(getline(classFile,line))
        {
            size_t stopper = line.length();
            line.append(1,',');
            newLiner = 0;

            while(newLiner <=stopper)
            {
                if(line[newLiner] == ',')
                {
                    classData.push_back(word);
                    word.clear();
                    newLiner++;
                }
                word.append(1,line[newLiner]);
                newLiner++;
            }
            this->rows++;
            bigDataFile.push_back(classData);
            classData.clear();
        }
    }


    this->matrixWithNumbers = new(std::nothrow) size_t*[rows];
    for(size_t i = 0; i < this-> rows ;i++)
    {
        this->matrixWithNumbers[i] = new(std::nothrow) size_t[this->columns];
        this->namesOfPeople.push_back(bigDataFile[i][0]);

        for(size_t j = 1; j < this->columns;j++)
        {
            matrixWithNumbers[i][j-1] = bigDataFile[i][j][0] - '0';
        }
    }
    this->countOfPeople = rows;
    this->countOfPlaces = columns - 1;
}

void convertFileToDataMatrix::printNamesOfPlaces()
{
    for(size_t i = 0; i < this->columns - 1; i++)
    {
        std::cout << this->namesOfPlaces[i] << std::endl;
    }
}

void convertFileToDataMatrix::printNamesOfPeople()
{
    for(size_t i = 0; i < this->rows; i++)
    {
        std::cout << this->namesOfPeople[i] << std::endl;
    }
}

size_t** convertFileToDataMatrix::transponateMatrix(size_t** matrixForTransponate)
{
    size_t** transponatedMatrix = new size_t*[this->countOfPlaces];
    for(size_t i = 0; i < this->countOfPlaces; i++)
    {
        transponatedMatrix[i] = new size_t[countOfPeople];
        for(size_t j = 0; j < countOfPeople; j++)
        {
            transponatedMatrix[i][j] = matrixForTransponate[j][i];
        }
    }

    return transponatedMatrix;
}

void convertFileToDataMatrix::printMatrixWithNumbers()
{
    for(size_t i = 0; i < this-> rows ;i++)
    {

        for(size_t j = 0; j < this->columns - 1;j++)
        {
            std::cout << matrixWithNumbers[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "count of people : " << countOfPeople << std::endl;
    std::cout << "count of places : " << countOfPlaces << std::endl;
}

size_t** convertFileToDataMatrix::multiplyMatrix(size_t** matrix1, size_t** matrix2, size_t countOfRC,size_t mult)
{
    size_t** newMatrix = new size_t*[countOfRC];
    for(size_t i = 0; i < countOfRC; i++)
    {

        newMatrix[i] = new size_t[countOfRC];
        for(size_t j = 0; j < countOfRC ;j++)
        {
            newMatrix[i][j] = 0;
            for(size_t k = 0; k < mult; k++)
            {
                newMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
            if(i == j)
            {
                newMatrix[i][j] = 0;
            }
        }
    }

    return newMatrix;
}

size_t convertFileToDataMatrix::mostFindedElement(size_t** matrix, size_t sizeOfMatrix)
{
    size_t largestElement = 0;

    for(size_t i = 0; i < sizeOfMatrix; ++i)
    {
        for(size_t j = 0; j < sizeOfMatrix; ++j)
        {
            if(largestElement < matrix[i][j])
            {
                largestElement = matrix[i][j];
            }
        }
    }

    return largestElement;
}

void convertFileToDataMatrix::printMostConnectedMan()
{
    size_t largestElement = mostFindedElement(multiplyMatrix(matrixWithNumbers,transponateMatrix(matrixWithNumbers),countOfPeople,countOfPlaces),countOfPeople);
    for(size_t i = 0; i < countOfPeople; ++i)
    {
        for(size_t j = 0; j < countOfPeople; ++j)
        {
            if(largestElement == multiplyMatrix(matrixWithNumbers,transponateMatrix(matrixWithNumbers),countOfPeople,countOfPlaces)[i][j])
            {
                std::cout << namesOfPeople[i] << std::endl;
            }
        }
    }
}

void convertFileToDataMatrix::printMostVisitedPlace()
{
    size_t largestElement = mostFindedElement(multiplyMatrix(transponateMatrix(matrixWithNumbers),matrixWithNumbers,countOfPlaces,countOfPeople),countOfPlaces);
    for(size_t i = 0; i < countOfPlaces; i++)
    {
        for(size_t j = 0; j < countOfPlaces; j++)
        {
            if(largestElement == multiplyMatrix(transponateMatrix(matrixWithNumbers),matrixWithNumbers,countOfPlaces,countOfPeople)[i][j])
            {
                std::cout << namesOfPlaces[i] << std::endl;
            }
        }
    }
}

void convertFileToDataMatrix::floydWarshall(size_t** matrix, size_t sizeOfMatrix)
{
    for(size_t i = 0; i < sizeOfMatrix; i++)
    {
        for(size_t j = 0; j < sizeOfMatrix; j++)
        {
            for(size_t k = 0; k < sizeOfMatrix; k++)
            {
                if ((matrix[j][i] * matrix[i][k] != 0) && (j != k))
                {
                    if ((matrix[j][i] + matrix[i][k] < matrix[j][k]) || (matrix[j][k] == 0))
                    {
                        matrix[j][k] = matrix[j][i] + matrix[i][k];
                    }
                }
            }
        }
    }
    for (size_t i = 0; i < sizeOfMatrix; i++)
    {
        std::cout<<"\nMinimum Cost With Respect to Node:" << i << std::endl;
        for (size_t j = 0; j < sizeOfMatrix; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
    }

}

void convertFileToDataMatrix::printFWresult()
{
    floydWarshall(
            multiplyMatrix(
                matrixWithNumbers,transponateMatrix(matrixWithNumbers),
                           countOfPeople,
                           countOfPlaces),
                          countOfPeople);
}
