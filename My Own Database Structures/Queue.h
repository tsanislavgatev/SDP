#pragma once
#include<iostream>


template <typename T>
struct element
{
    T data;
    element<T>* next;
    element(const T& other)
    {
        data = other;
        next = 0;
    }
};


template <typename T>
class Queue
{
    public:
        Queue();
        ~Queue();
        bool isEmpty();
        void enqueue(const T& data);
        void dequeue();
        T frontElement();

    private:
        element<T>* pFirst;
        element<T>* pLast;
        int countOfElements;
        T firstElement;
};

template<typename T>
Queue<T>::Queue()
{
    this -> pFirst = NULL;
    this -> pLast = NULL;
    this -> countOfElements = 0;
}

template<typename T>
Queue<T>::~Queue()
{
    while(!isEmpty())
    {
        dequeue();
    }
}

template<typename T>
void Queue<T>::enqueue(const T& x)
{
    element<T>* e = new element <T>(x);
    if(isEmpty())
    {
        this -> pFirst = e;
    }
    else
    {
        pLast -> next = e;
    }
    pLast = e;
    countOfElements++;
}

template<typename T>
bool Queue<T>::isEmpty()
{
    return(countOfElements == 0);
}

template<typename T>
void Queue<T>::dequeue()
{
    if(isEmpty())
    {
        std::cout << "The Queue Is Empty ! " << std::endl;
    }
    else
    {
        element <T>* e = pFirst;
        pFirst = pFirst -> next;
        e -> next = NULL;
        delete e;
        --countOfElements;
    }
}

template<typename T>
T Queue<T>::frontElement()
{
    if(isEmpty()) std::cout << " Queue Is Empty " << std::endl;
    return pFirst -> data;
}
