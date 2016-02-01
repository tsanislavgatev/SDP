#pragma once
#include <iostream>
#include <string>

template <typename T>
class DynamicArray
{
    public:
        DynamicArray();//
        DynamicArray(size_t inputSize);
        ~DynamicArray();//
        DynamicArray(const DynamicArray<T> &other);
        DynamicArray& operator=(const DynamicArray<T> &other);

    private:
        T* Array;
        size_t sizeOfArray;
        size_t countOfElements;

    public:
        bool isEmpty(); //
        void printArray();
        T operator[](size_t);//
        void setSize(size_t);//
        size_t getSizeOfArray();//
        size_t getCountOfElements();//
        void addElement(T);//

    private:
        void clearArray();//
        void resizeArray();//
        void copyArray(const DynamicArray<T>&);//
        T getElementAt(size_t);//
};

template<typename T>
DynamicArray<T>::DynamicArray(size_t inputSize)
{
    this->setSize(inputSize);
    this->countOfElements = 0;
    this->Array = new T[inputSize];
}

template<typename T>
DynamicArray<T>::DynamicArray()
{
    this -> sizeOfArray = 4;
    this -> countOfElements = 0;
    this -> Array = new T[sizeOfArray];
}

template<typename T>
DynamicArray<T>::~DynamicArray()
{
    this->clearArray();
}

template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T> &other)
{
    this->copyArray(other);
}

template<typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T> &other)
{
    if(this != &other)
    {
        this->clearArray();
		this->copyArray(other);
	}

	return *this;
}

template<typename T>
bool DynamicArray<T>::isEmpty()
{
    if(countOfElements == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template<typename T>
void DynamicArray<T>::clearArray()
{
    delete[]Array;

    Array = NULL;
    countOfElements = 0;
    sizeOfArray = 0;
}

template<typename T>
T DynamicArray<T>::getElementAt(size_t index)
{
    if(index > this->countOfElements || index < 0) return false;
    return this -> Array[index];
}

template<typename T>
void DynamicArray<T>::setSize(size_t inputSize)
{
    this -> sizeOfArray = inputSize;
}

template<typename T>
void DynamicArray<T>::copyArray(const DynamicArray<T> &other)
{
    this->sizeOfArray = other.sizeOfArray;
    this->countOfElements = other.countOfElements;
    this->Array = new T[other.sizeOfArray];
    for(size_t i = 0; i < other.countOfElements; i++)
    {
        this -> Array[i] = other.Array[i];
    }
}

template<typename T>
size_t DynamicArray<T>::getSizeOfArray()
{
    return this->sizeOfArray;
}

template<typename T>
size_t DynamicArray<T>::getCountOfElements()
{
    return this->countOfElements;
}

template<typename T>
T DynamicArray<T>::operator[](size_t index)
{
    return getElementAt(index);
}

template<typename T>
void DynamicArray<T>::resizeArray()
{
    this -> sizeOfArray *= 2;
    T* tempArray = new T[this->sizeOfArray];

    for(size_t i = 0; i < this -> countOfElements; i++)
    {
        tempArray[i] = Array[i];
    }

    delete[]this->Array;

    this->Array = tempArray;
}

template<typename T>
void DynamicArray<T>::addElement(T elementForAdd)
{
    if(this->countOfElements == sizeOfArray)
    {
        this -> resizeArray();
    }
    this->Array[countOfElements] = elementForAdd;
    this->countOfElements++;
}

template<typename T>
void DynamicArray<T>::printArray()
{
    std::cout << "\nPrinting Array : " << std::endl;
    for(size_t i = 0; i < this->countOfElements; i++)
    {
        std::cout<< this->Array[i] << std::endl;
    }
}
