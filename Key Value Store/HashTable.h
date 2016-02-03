#pragma once
#include <iostream>
#include "include/Pair.h"
#include "include/Hash.h"
#include "DynamicArray.h"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

template <typename D,typename K>
class HashTable
{
    public:
        HashTable()
        {
            this->tableSize = 12289;
            hashArray = new std::vector<Pair<D,K> >[tableSize];
        }
        ~HashTable()
        {
            delete[] hashArray;
        }
    private:
        size_t tableSize;
        std::vector<Pair<D,K> >* hashArray;
    public:
        void addElement(Pair<D,K>);
        bool findElementWithKey(std::string);
    private:
        std::string generateFileName(int);
        bool isThereAFileWithName(std::string);
};

template <typename D,typename K>
void HashTable<D,K>::addElement(Pair<D,K> item)
{
    Hash hashFunc;
    int index = hashFunc.hashFunc(item.key);
    std::cout << "Data : " << item.data<< " Key : " << item.key << std::endl;
    std::cout << "The index is : " << index << std::endl;


    std::string nameOfFile = this->generateFileName(index);

    //std::cout << nameOfFile << std::endl;

    int length = nameOfFile.length();
    char* finalName = new char[length + 1];
    for(int i = 0; i < length; i++)
    {
        finalName[i] = nameOfFile[i];
    }
    finalName[length] = '\0';

    //std::cout << finalName << std::endl;

    std::ofstream fileToWrite;
    fileToWrite.open(finalName, std::ios::binary);
    //data
    int lengthOfData = item.data.length();
    fileToWrite << lengthOfData << "\n";
    fileToWrite.write(item.data.c_str(), item.data.length());
    //key
    int lengthOfKey = item.key.length();
    fileToWrite <<"\n" << lengthOfKey << "\n";
    fileToWrite.write(item.key.c_str(), item.key.length());

    fileToWrite.close();
    delete[] finalName;

    Pair<D,K> tempPair;

    tempPair.data = item.data;
    tempPair.key = item.key;
    this->hashArray[index].push_back(tempPair);
}

template <typename D, typename K>
bool HashTable<D,K>::findElementWithKey(std::string itemKey)
{
    Hash hashFunc;
    size_t index = hashFunc.hashFunc(itemKey);

    std::string nameOfFile = this->generateFileName(index);

    //std::cout << nameOfFile << std::endl;

    int length = nameOfFile.length();
    char* finalName = new char[length + 1];
    for(int i = 0; i < length; i++)
    {
        finalName[i] = nameOfFile[i];
    }
    finalName[length] = '\0';

    std::ifstream fileToRead;

    fileToRead.open(finalName,std::ios::in|std::ios::binary);

    if(!isThereAFileWithName(finalName))
    {
        std::cerr << "No such an element !! " << std::endl;
        return false;
    }
    else
    {
        if(!fileToRead.is_open())
        {
            return false;
        }
        std::string dataReader;
        std::string lengthForRead;
        std::getline(fileToRead,lengthForRead);
        std::getline(fileToRead,dataReader);
        std::cout << "The Data is : " << lengthForRead << "  " << dataReader << std::endl;
    }

    fileToRead.close();
    delete[] finalName;
    return true;
}

template <typename D, typename K>
std::string HashTable<D,K>::generateFileName(int key)
{
    std::string folderName = "store/";
    std::string endOfName = ".dat";

    std::stringstream ss;
    ss << key;
    std::string actualNameOfFile = ss.str();

    actualNameOfFile += endOfName;
    std::string nameOfFile = folderName + actualNameOfFile;

    return nameOfFile;
}

template <typename D, typename K>
bool HashTable<D,K>::isThereAFileWithName(std::string nameOfFile)
{
    int length = nameOfFile.length();
    char* finalName = new char[length + 1];
    for(int i = 0; i < length; i++)
    {
        finalName[i] = nameOfFile[i];
    }
    finalName[length] = '\0';

    std::ifstream check(finalName, std::ios::binary);

    if(check)
    {
        delete[]finalName;

        check.close();
        return true;
    }

    delete[]finalName;
    return false;
}
