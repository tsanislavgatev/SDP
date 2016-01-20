#include "StringReader.h"

StringReader::StringReader()
{

}

StringReader::StringReader(std::string inputString)
{
    this->stringForRead = inputString;
    this->readStringAndMakeTree(inputString);
}

void StringReader::readStringAndMakeTree(std::string inputString)
{
    size_t indx = 0;
   // size_t vectIndx = 0;
    do{
        if(inputString[indx] == '(')
        {
            //vectIndx++;
            this->stackForLevels.push(this->vectorOfVectorsWithChildren.size());
            this->vectorOfVectorsWithChildren.push_back(std::vector<size_t>());
        }
        else if(inputString[indx] == ')')
        {
            size_t varForPush = this->stackForLevels.top();
            this->stackForLevels.pop();
            if(!this->stackForLevels.isEmpty())
            {
                this->vectorOfVectorsWithChildren[this->stackForLevels.top()].push_back(varForPush);
            }
            //std::cout << "Stack top " << stackForLevels.top() << std::endl;
        }
        indx++;
    }while(indx < stringForRead.length());
}

std::vector<std::vector<size_t> > StringReader::getTreeVector() const
{
    return this->vectorOfVectorsWithChildren;
}

void StringReader::printTree()
{
    //std::cout << this->vectorOfVectorsWithChildren.size();
    for(int i = 0; i < this->vectorOfVectorsWithChildren.size();i++)
    {
        //std::cout << this-> vectorOfVectorsWithChildren[i].size() << std::endl;
        for(int j = 0; j < this-> vectorOfVectorsWithChildren[i].size();j++)
        {
            std::cout << " Level " << i << " " << vectorOfVectorsWithChildren[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void StringReader::sortAllVectors()
{
    for(int i = 0; i < this->vectorOfVectorsWithChildren.size(); i++)
    {
        if(this->vectorOfVectorsWithChildren[i].size() != 0)
        {
            size_t j = 0;
            size_t temp = 0;
            std::vector<size_t> tempVec;

            for (size_t k = 0; k < this->vectorOfVectorsWithChildren[i].size(); k++)
            {
                j = k;
                while (j > 0 &&
                       this->vectorOfVectorsWithChildren[this->vectorOfVectorsWithChildren[i][j]].size()
                       <  this->vectorOfVectorsWithChildren[this->vectorOfVectorsWithChildren[i][j-1]].size())
                {
                    temp = this->vectorOfVectorsWithChildren[i][j];
                    tempVec = this->vectorOfVectorsWithChildren[this->vectorOfVectorsWithChildren[i][j]];
                    this->vectorOfVectorsWithChildren[i][j] = this->vectorOfVectorsWithChildren[i][j - 1];
                    this->vectorOfVectorsWithChildren[this->vectorOfVectorsWithChildren[i][j]] = this->vectorOfVectorsWithChildren[this->vectorOfVectorsWithChildren[i][j - 1]];
                    this->vectorOfVectorsWithChildren[i][j - 1] = temp;
                    this->vectorOfVectorsWithChildren[this->vectorOfVectorsWithChildren[i][j - 1]] = tempVec;
                    j--;
                }

            }
        }
    }
}


