#pragma once
#include <iostream>
#include "include/Pair.h"
#include "include/Hash.h"
#include "DynamicArray.h"
#include <string>
#include <vector>

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
};

template <typename D,typename K>
void HashTable<D,K>::addElement(Pair<D,K> item)
{
    Hash hashFunc;
    size_t index = hashFunc.hashFunc(item.key);
    std::cout << "Data : " << item.data<< " Key : " << item.key << std::endl;
    std::cout << "The index is : " << index << std::endl;
    //std::cout << "The size of the array at index : " << hashArray[index].getCountOfElements() << std::endl;
    //std::cout << "The size Of Big Array : " << this->tableSize << std::endl;

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
    std::cout << "Index ::: " << index << std::endl;
    if(this->hashArray[index].size() == 0)
    {
        std::cerr << "No such an element !! " << std::endl;
    }
    else
    {
       for(size_t i = 0; i < this->hashArray[index].size(); i++)
       {
           if(itemKey == this->hashArray[index][i].key)
           {
               std::cout << this->hashArray[index][i].data << std::endl;
           }
       }
    }

}
