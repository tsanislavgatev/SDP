#pragma once

#include <cstring>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

class convertFileToDataMatrix
{
    public:
        convertFileToDataMatrix();
        virtual ~convertFileToDataMatrix();
        convertFileToDataMatrix(const convertFileToDataMatrix& other);
        convertFileToDataMatrix& operator=(const convertFileToDataMatrix& other);

    private:
        size_t columns;
        size_t rows;
        char* nameOfFile;
        std::vector<std::string> namesOfPeople;
        std::vector<std::string> namesOfPlaces;
        size_t** matrixWithNumbers;
        size_t countOfPeople;
        size_t countOfPlaces;

    public:
        void setNameOfFile(char*);
        void readTheFile();
        void printNamesOfPeople();
        void printNamesOfPlaces();
        void printMatrixWithNumbers();
        void printMostConnectedMan();
        void printMostVisitedPlace();
        void printFWresult();

    private:
        size_t** transponateMatrix(size_t**);
        size_t** multiplyMatrix(size_t**, size_t**,size_t,size_t);
        size_t mostFindedElement(size_t**, size_t);
        void floydWarshall(size_t**, size_t);
};

