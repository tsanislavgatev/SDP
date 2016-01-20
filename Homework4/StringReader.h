#pragma once
#include <stack>
#include <vector>
#include "LinkedStack.h"
#include "DynamicArray.h"
#include <iostream>
#include <cstring>

class StringReader
{
    public:
        StringReader();
        StringReader(std::string);

    private:
        LinkedStack<size_t> stackForLevels;
        std::vector<std::vector<size_t> > vectorOfVectorsWithChildren;
        std::string stringForRead;

    public:
        std::vector<std::vector<size_t> > getTreeVector() const;
        void printTree();
        void sortAllVectors();

    private:
        void readStringAndMakeTree(std::string);
};


