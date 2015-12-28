#include "namesDictionary.h"
#include <iostream>
#include <cstring>

namesDictionary::namesDictionary()
{
    this->dictionary = NULL;
    this->countOfNames = 0;
    this->intervalBegin = 0;
    this-> intervalEnd = 0;
}

namesDictionary::namesDictionary(long long countOfN)
{
    this->countOfNames = countOfN;
    this->dictionary = new char*[countOfNames];
    this->intervalBegin = 0;
    this->intervalEnd = countOfN - 1;
}

namesDictionary::~namesDictionary()
{
    this->destroyArray();
}

namesDictionary::namesDictionary(const namesDictionary& other)
{
    // copyconstructor
}

namesDictionary& namesDictionary::operator=(const namesDictionary& other)
{
    if (this == &other) return *this; // handle self assignment
    //assignment operator
    return *this;
}

void namesDictionary::destroyArray()
{
    for(int i = 0; i < this-> countOfNames; i++)
    {
        delete[]this->dictionary[i];
    }
    delete[] this->dictionary;
}

void namesDictionary::inputWords()
{
    for(int i = 0; i < this->countOfNames; i++)
    {
        this->dictionary[i] = new char[9];
        //std::cout << " __ " ;
        std::cin >> dictionary[i];
    }
}

char** namesDictionary::getDictionary()
{
    return this->dictionary;
}

void namesDictionary::printArray()
{
    for(int i = 0; i < countOfNames; i++)
    {
        std::cout << dictionary[i] << std::endl;
    }
}

void namesDictionary::setInterval(int beg, int endd)
{
    this->intervalBegin = beg;
    this->intervalEnd = endd;
    //std::cout << this->intervalBegin <<  " " << this->intervalEnd << std::endl;
}

int namesDictionary::countThePrefixContainers(char* prefix)
{
    int length = strlen(prefix);
    prefixCounter = 0;
    for(int i = this->intervalBegin; i <= this -> intervalEnd; i++)
    {
        if(strncmp(dictionary[i],prefix,length) == 0)
        {
            prefixCounter++;
        }
    }

    return prefixCounter;
}

void namesDictionary::mergeArr(int low ,int mid , int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;

    char** temp = new char*[this->countOfNames];

    while(i <= mid && j <= high)
    {
        if(strcmp(dictionary[i], dictionary[j]) < 0)
        {
            temp[k] = dictionary[i];
            i++;
        }
        else
        {
            temp[k] = dictionary[j];
            j++;
        }
        k++;
    }
    if(i > mid)
    {
        for(int h = j ;h <= high ; h++ )
        {
            temp[k] = dictionary[h];
            k++;
        }
    }
    else
        for(int h = i; h<= mid ; h++ )
        {
            temp[k] = dictionary[h];
            k++;
        }
    for(int indx = low; indx <= high ; indx++)
    {
        dictionary[indx] = temp[indx];
    }
    delete[] temp;
}

void namesDictionary::mergeSortArr(int low , int high)
{
    int mid = 0;
    if(low < high)
    {
        mid = (low + high)/2;
        mergeSortArr(low , mid);
        mergeSortArr(mid  + 1, high);
        mergeArr(low, mid, high);
    }
}

void namesDictionary::sortTheArray()
{
    mergeSortArr(this->intervalBegin,this->intervalEnd - 1);
}
