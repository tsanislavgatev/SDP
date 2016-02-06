#pragma once

#include <iostream>

template <typename T>
struct Node
{
    T data;
    Node<T>* pNext;

    Node(const T &dat, Node<T>* next = NULL)
    {
        data = dat;
        pNext = next;
    }

    bool isLast()
    {
        return pNext == NULL;
    }
};

template <typename T>
class Iterator
{
    public:
        Iterator(Node<T>* firstNode);

    private:
        Node<T>* pFirst;
        Node<T>* pCurrent;

    public:
        T getCurrent()const;
        void setCurrent(T const &);
        void goForward();
        void goToFirstElem();
        void goToLastElem();
        bool isLastElem();
};

template <typename T>
Iterator<T>::Iterator(Node<T>* firstNode)
{
    this->pFirst = firstNode;
    this->pCurrent = firstNode;
}

template <typename T>
T Iterator<T>::getCurrent() const
{
    return this->pCurrent->data;
}

template <typename T>
void Iterator<T>::setCurrent(T const &dataForSet)
{
    this->pCurrent->data = dataForSet;
}

template <typename T>
void Iterator<T>::goForward()
{
    if(this->pCurrent)
    {
        this->pCurrent = this->pCurrent->pNext;
    }
}

template <typename T>
void Iterator<T>::goToFirstElem()
{
    this->pCurrent = this->pFirst;
}

template <typename T>
void Iterator<T>::goToLastElem()
{
    while(!isLastElem())
    {
        this->goForward();
    }
}

template <typename T>
bool Iterator<T>::isLastElem()
{
    return this->pCurrent->isLast();
}
