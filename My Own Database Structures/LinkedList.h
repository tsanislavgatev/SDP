#pragma once

#include <iostream>
#include "Iterator.h"

template <typename T>
class LinkedList
{
    private:
        Node<T>* pFirst;
        Node<T>* pLast;
        size_t countOfNodes;

    public:
        LinkedList();
        ~LinkedList();
        LinkedList(const LinkedList& other);
        LinkedList& operator=(const LinkedList& other);

    private:
        void copyList(const LinkedList &other);
        void initiateVariables();
        Node<T>* copyChain(Node<T>* pFirstNode);
        void destroyChain();
        Node<T>* findEndOfChain();

    public:
        bool isEmpty();
        size_t getCount();
        void addAtTheEnd(T const &);
        void addAtTheBegin(T const &);
        void removeAtTheEnd();
        void removeAtTheBegin();
        T const & getLast();
        T const & getFirst();
        void insertAfter(int, T const &);
        void insertBefore(int, T const &);
        void removeAt(int);
        T const & getAt(int);
        void setAt(int, T const &);
        void printList();
        Iterator<T> getIterator();

    private:
        Node<T>* findNodeAt(int);
};

template <typename T>
LinkedList<T>::LinkedList()
{
    this->initiateVariables();
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    this->destroyChain();
    this->initiateVariables();
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList& other)
{
    this->initiateVariables();
    this->copyList(other);
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList& other)
{
    if (this != &other)
    {
        this->destroyChain();
        this->initiateVariables();
        this->copyList(other);
    }
    return *this;
}

template <typename T>
void LinkedList<T>::initiateVariables()
{
    this->pFirst = NULL;
    this->pLast = NULL;
    this->countOfNodes = 0;
}

template <typename T>
void LinkedList<T>::copyList(const LinkedList &other)
{
    if(!other.isEmpty())
    {
        Node<T> *pTempChain = copyChain(other.pFirst);
        if(pTempChain)
        {
            this->pLast->pNext = pTempChain;
            this->pLast = findEndOfChain(pTempChain);
        }
    }
}

template <typename T>
Node<T>* LinkedList<T>::copyChain(Node<T>* pFirstNode)
{
    if(pFirstNode)
	{
		Node<T>* pNewChain = new Node<T>(pFirstNode);
		Node<T>* pCopyFrom = pFirstNode->pNext;
		Node<T>* pCopyAfter = pNewChain;

		while(pCopyFrom)
		{
			if(!pCopyAfter)
			{
				this->destroyChain(pNewChain);
				pNewChain = NULL;

				break;
			}

			pCopyAfter->pNext = new Node<T>(pCopyFrom);
			pCopyAfter = pCopyAfter->pNext;

			pCopyFrom = pCopyFrom->pNext;
		}

		return pNewChain;
	}

	return NULL;
}

template <typename T>
void LinkedList<T>::destroyChain()
{
    Node<T>* temp = this->pFirst;
	while(this->pFirst)
	{
		temp = pFirst;
		pFirst = pFirst->pNext;
		delete temp;
	}
}

template <typename T>
Node<T>* LinkedList<T>::findEndOfChain()
{
    if(pFirst)
	{
		while(pFirst->pNext)
		{
			pFirst = pFirst->pNext;
		}
	}

	return pFirst;
}

template <typename T>
bool  LinkedList<T>::isEmpty()
{
    return this->countOfNodes == 0;
}

template <typename T>
void LinkedList<T>::addAtTheBegin(T const & data)
{
    Node<T> *pNewNode = new(std::nothrow) Node<T>(data,this->pFirst);
    if(pNewNode)
    {
        if(this->isEmpty())
        {
            this->pLast = pNewNode;
        }
        this->pFirst = pNewNode;

        this->countOfNodes++;
    }
}

template <typename T>
void LinkedList<T>::addAtTheEnd(T const &data)
{
    Node<T>* pNewNode = new Node<T>(data);
    if(pNewNode)
    {
        if(this->isEmpty())
        {
            this->pFirst = pNewNode;
            this->pLast = pNewNode;
        }
        else
        {
            this->pLast->pNext = pNewNode;
            this->pLast = pNewNode;
        }

        this->countOfNodes++;
    }
}

template <typename T>
void LinkedList<T>::removeAtTheBegin()
{
    if(!this->isEmpty())
    {
        Node<T>* pPrevHead = this->pFirst;
        this->pFirst = this->pFirst->pNext;
        if(this->pFirst == NULL)
        {
            this->pLast = NULL;
        }

        this->countOfNodes--;

        delete pPrevHead;
    }
}

template <typename T>
void LinkedList<T>::removeAtTheEnd()
{
    if(!this->isEmpty())
    {
        removeAt(this->countOfNodes - 1);
    }
}

template <typename T>
T const & LinkedList<T>::getFirst()
{
    return this->pFirst->data;
}

template <typename T>
T const & LinkedList<T>::getLast()
{
    return this->pLast->data;
}

template <typename T>
void LinkedList<T>::insertAfter(int indx,T const & data)
{
    Node<T>* pNodeAtIndx = findNodeAt(indx);
    if(pNodeAtIndx)
    {
        Node<T>* pNewNode = new Node<T>(data,pNodeAtIndx->pNext);
        if(pNewNode)
        {
            pNodeAtIndx->pNext = pNewNode;
            if(pNodeAtIndx == this->pLast)
            {
                this->pLast = pNewNode;
            }

            this->countOfNodes++;
        }
    }
}

template <typename T>
Node<T>* LinkedList<T>::findNodeAt(int indx)
{
	if(indx < 0 || indx >= this->countOfNodes)
	{
		return NULL;
	}
	else
	{
		Node<T> *p = this->pFirst;

		for(int i = 0; i < indx; i++)
		{
			if(p->pNext)
            {
                p = p->pNext;
            }
		}

		return p;
	}
}

template <typename T>
void LinkedList<T>::insertBefore(int indx, T const & data)
{
    if(indx == 0)
    {
        return addAtTheBegin(data);
    }
    else
    {
         return insertAfter(indx - 1, data);
    }
}

template <class T>
void LinkedList<T>::removeAt(int indx)
{
	if(indx == 0)
	{
        this->removeAtTheBegin();
	}
	else
	{
		Node<T> *pNodeBeforeIndx = findNodeAt(indx - 1);
		Node<T> *pNodeAtIndx = pNodeBeforeIndx->pNext;
		if(indx == this->countOfNodes - 1)
		{
			this->pLast = pNodeBeforeIndx;
		}
        pNodeBeforeIndx->pNext = pNodeAtIndx->pNext;

		delete pNodeAtIndx;

		this->countOfNodes--;
	}
}

template <typename T>
T const & LinkedList<T>::getAt(int indx)
{
	Node<T> *pNode = findNodeAt(indx);

	return pNode->data;
}

template <typename T>
void LinkedList<T>::setAt(int indx, T const & dataT)
{
	Node<T> *pNode = findNodeAt(indx);
	if(pNode != NULL)
	{
		pNode->data = dataT;
	}
}

template <typename T>
size_t LinkedList<T>::getCount()
{
    return this->countOfNodes;
}

template <typename T>
void LinkedList<T>::printList()
{
    for(int i = 0;i < this->countOfNodes; i++)
    {
        std::cout << getAt(i) << std::endl;
    }
}

template <typename T>
Iterator<T> LinkedList<T>::getIterator()
{
    return Iterator<T>(this->pFirst);
}
