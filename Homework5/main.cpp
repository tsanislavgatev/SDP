#include <iostream>
#include "convertFileToDataMatrix.h"

using namespace std;

int main()
{
    convertFileToDataMatrix test;
    test.setNameOfFile("d1.csv");
    test.readTheFile();
    //test.printNamesOfPlaces();
    //test.printNamesOfPeople();
    test.printMatrixWithNumbers();
    std::cout << "The people with the most connections : " << std::endl;
    test.printMostConnectedMan();
    std::cout << "\nThe places with the most visits : " << std::endl;
    test.printMostVisitedPlace();
    //std::cout << "The Floyd-Warshall algorithm results : " << std::endl;
    //test.printFWresult();

    return 0;
}
