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
        bool addElement(Pair<D,K>);
        bool findElementWithKey(std::string);
        bool deleteElementWithKey(std::string);
    private:
        std::string generateFileName(int);
        bool isThereAFileWithName(std::string);
        bool isContaining(std::string, char*);
        int countOfElementsInFile(char*);
};

template <typename D,typename K>
bool HashTable<D,K>::addElement(Pair<D,K> item)
{
    Hash hashFunc;
    int index = hashFunc.hashFunc(item.key);

    std::string nameOfFile = this->generateFileName(index);

    int length = nameOfFile.length();
    char* finalName = new char[length + 1];
    for(int i = 0; i < length; i++)
    {
        finalName[i] = nameOfFile[i];
    }
    finalName[length] = '\0';

    std::ofstream fileToWrite;

    if(isThereAFileWithName(finalName))
    {
        if(this->isContaining(item.key,finalName))
        {
            std::cout << "That item was already stored ! " << std::endl;
            return false;
        }
        fileToWrite.open(finalName, std::ios::binary|std::ios::app);
        fileToWrite << "\n";
    }
    else
    {
        fileToWrite.open(finalName, std::ios::binary);
        if(!fileToWrite.is_open())
        {
            return false;
        }

        std::cout << "Item Stored ! " << std::endl;
        std::cout << "Data : " << item.data<< " Key : " << item.key << std::endl;
        std::cout << "The index is : " << index << std::endl;
    }

    //data
    fileToWrite.write(item.key.c_str(), item.key.length());

    fileToWrite <<"\n";
    //key
    fileToWrite.write(item.data.c_str(), item.data.length());

    char endOfPair = '*';
    fileToWrite <<"\n" << endOfPair;

    fileToWrite.close();
    delete[] finalName;

    return true;
}

template <typename D, typename K>
bool HashTable<D,K>::findElementWithKey(std::string itemKey)
{
    Hash hashFunc;
    size_t index = hashFunc.hashFunc(itemKey);

    std::string nameOfFile = this->generateFileName(index);

    int length = nameOfFile.length();
    char* finalName = new char[length + 1];
    for(int i = 0; i < length; i++)
    {
        finalName[i] = nameOfFile[i];
    }
    finalName[length] = '\0';

    std::ifstream fileToRead;

    if(!isThereAFileWithName(finalName))
    {
        std::cerr << "No such an element !! " << std::endl;
        return false;
    }
    else
    {
        fileToRead.open(finalName,std::ios::in|std::ios::binary);
        if(!fileToRead.is_open())
        {
            return false;
        }

        std::string dataReader;
        std::string keyHolder;

        while(!fileToRead.eof())
        {
            std::getline(fileToRead,keyHolder);
            if(keyHolder.compare(itemKey) == 0)
            {
                std::getline(fileToRead,dataReader);
                std::cout << "\nThe Data in this item is : " << dataReader << std::endl;
            }
            else
            {
                std::string lineSkipper;
                std::getline(fileToRead,lineSkipper);
                std::getline(fileToRead,lineSkipper);
            }
        }
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

template <typename D,typename K>
bool HashTable<D,K>::isContaining(std::string itemKey, char* fileName)
{
    std::ifstream check(fileName,std::ios::binary);
    if(check)
    {
        std::string keyHolder;
        std::string linePasser;
        while(!check.eof())
        {
            std::getline(check,keyHolder);
            if(itemKey.compare(keyHolder) == 0)
            {
                return true;
            }
            std::getline(check,linePasser);
            std::getline(check,linePasser);
        }

    }

    return false;
}

template <typename D, typename K>
bool HashTable<D,K>::deleteElementWithKey(std::string itemKey)
{
    Hash hashFunc;
    size_t index = hashFunc.hashFunc(itemKey);

    std::string nameOfFile = this->generateFileName(index);

    int length = nameOfFile.length();
    char* finalName = new char[length + 1];
    for(int i = 0; i < length; i++)
    {
        finalName[i] = nameOfFile[i];
    }
    finalName[length] = '\0';

    std::ifstream fileToRead;

    if(!isThereAFileWithName(finalName))
    {
        std::cerr << "The element you are trying to delete, is not in the store !! " << std::endl;
        return false;
    }

    int countOfElements = this->countOfElementsInFile(finalName);

    if(countOfElements == 1)
    {
        std::remove(finalName);

        std::cout << "Item Deleted ! " << std::endl;

        return true;
    }
    else
    {
        if(!isContaining(itemKey,finalName))
        {
            std::cerr << "The element you are trying to delete, is not in the store !! " << std::endl;
            return false;
        }
        DynamicArray<std::string> newFileDataHolder;

        fileToRead.open(finalName,std::ios::in|std::ios::binary);
        if(!fileToRead.is_open())
        {
            return false;
        }
        while(!fileToRead.eof())
        {
            std::string lineHolder;
            std::getline(fileToRead,lineHolder);
            std::string lineSkipper;
            if(lineHolder.compare(itemKey) == 0)
            {
                std::getline(fileToRead,lineSkipper);
                std::getline(fileToRead,lineSkipper);
            }
            else
            {
                std::cout << lineHolder << std::endl;
                newFileDataHolder.addElement(lineHolder);
            }
        }
        fileToRead.close();
        std::cout << "Item is deleted !" << std::endl;
        std::remove(finalName);

        std::ofstream fileToWrite;
        fileToWrite.open(finalName, std::ios::binary);
        //std::cout << newFileDataHolder.getCountOfElements() << std::endl;
        int countOfRows = newFileDataHolder.getCountOfElements();
        for(int i = 0; i < countOfRows - 3;i++)
        {
            fileToWrite.write(newFileDataHolder[i].c_str(), newFileDataHolder[i].length());
            fileToWrite << "\n";
        }
        fileToWrite.write(newFileDataHolder[countOfRows - 3].c_str(), newFileDataHolder[countOfRows - 3].length());
        fileToWrite << "\n";
        fileToWrite.write(newFileDataHolder[countOfRows - 2].c_str(), newFileDataHolder[countOfRows - 2].length());
        fileToWrite << "\n";
        fileToWrite.write(newFileDataHolder[countOfRows - 1].c_str(), newFileDataHolder[countOfRows - 1].length());

        fileToWrite.close();

        delete[] finalName;
    }

    return false;
}

template <typename D, typename K>
int HashTable<D,K>::countOfElementsInFile(char* nameOfFile)
{
    int counter = 1;
    std::ifstream counterStream(nameOfFile,std::ios::binary);
    if(counterStream)
    {
        std::string linePasser;
        while(!counterStream.eof())
        {
            std::getline(counterStream,linePasser);
            counter++;
        }

    }

    return counter/3;
}
