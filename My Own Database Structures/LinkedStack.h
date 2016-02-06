#pragma once
#include<iostream>
#include<assert.h>

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
class LinkedStack
{
    private:
        void copyFrom(const LinkedStack<T>& other);
        void destroy();
    public:
        LinkedStack();
        ~LinkedStack();
        LinkedStack(const LinkedStack& other);
        LinkedStack& operator=(const LinkedStack& other);

    public:
        bool isEmpty() const; // proverqva dali e prazen
        void pop(); // izkarva element
        void push(const T& newElem); // izbutva elementa
        void init(); // nulira
        T top();
    private:
        element<T>* tos; // pointer to topElem
        int used;
};

template<typename T>
LinkedStack<T>::LinkedStack()
{
    init();
}
template<typename T>
LinkedStack<T>::~LinkedStack()
{
    destroy();
    //std::cout << "dest" << std::endl;
}
template<typename T>
LinkedStack<T>::LinkedStack(const LinkedStack& other)
{
    init();
    copyFrom(other);
}

template<typename T>
LinkedStack<T>& LinkedStack<T>::operator=(const LinkedStack& other)
{
	if (this != other)
	{
        destroy();
		copyFrom(other);
	}

	return *this;
}

template<typename T>
void LinkedStack<T>::init()
{
    this -> tos = 0;
    this -> used = 0;
    //std::cout << "init" << std::endl;
}

template<typename T>
bool LinkedStack<T>::isEmpty() const
{
    return tos == 0;
}

template<typename T>
void LinkedStack<T>::pop()
{
    if(isEmpty())
    {
        //std::cout << "EE" << std::endl;
        //throw "Empty Stack";
    }
    element<T>* next = tos -> next;
    delete tos;
    tos = next;
    //std::cout << "POP" << std::endl;
    used --;
}

template<typename T>
void LinkedStack<T>::push(const T& newElem)
{

    element<T>* pElem= new (std::nothrow)element<T>(newElem);
    pElem -> next = tos;
    tos = pElem;
    //std::cout << "push" << std::endl;
    used ++;
}

template<typename T>
void LinkedStack<T>::destroy()
{
    while(used > 0)
    {
        pop();
    }
}

template<typename T>
T LinkedStack<T>::top()
{
    if(isEmpty()) std::cout << "Stack Is Empty " << std::endl;
    return tos -> data;
}

template<typename T>
void LinkedStack<T>::copyFrom(const LinkedStack<T>& other)
{
    // set a copy function
}
