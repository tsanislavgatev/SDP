#pragma once

#include <iostream>
#include "TreeItem.h"

template <typename T>
class Tree
{
    public:
        Tree()
        {
            this->root = 0;
        }

    private:
        TreeItem<T>* root;

    public:
        void insertElement(const T& value)
        {
            addElement(value,root);
        }

        void printTree()
        {
            this->printTrie(root);
        }

        void deleteElement(const T& value)
        {
            this->deleteItem(value,root);
        }

    private:
        void addElement(const T& value, TreeItem<T>*& node)
        {
            if(node)
            {
                if(value == node->data)
                {
                    return;
                }
                if(value < node->data)
                {
                    addElement(value,node->pLeft);
                }
                if(value >= node->data)
                {
                    addElement(value,node->pRight);
                }
            }
            else
            {
                node = new TreeItem<T>;
                node->data = value;
                node->pLeft = 0;
                node->pRight = 0;
            }
        }

        void printTrie(TreeItem<T>*& node)
        {
            if(node)
            {
                printTrie(node->pLeft);

                std::cout << node->data << " ";

                printTrie(node->pRight);
            }
        }

        void deleteItem(const T& value,TreeItem<T>*& node)
        {
            if(node)
            {
                if( value < node->data)
                {
                    deleteItem(value,node->pLeft);
                }
                if(value > node->data)
                {
                    deleteItem(value,node->pRight);
                }
                if(value == node->data)
                {
                    if(node->pLeft && node->pRight)
                    {
                        T max = findMax(node->pLeft);

                        node->data = max;
                        deleteItem(max,node->pLeft);
                    }
                    else if(node->pLeft)
                    {
                        TreeItem<T>* toDel = node;
                        node = node->pLeft;
                        delete toDel;
                        toDel = 0;
                    }
                    else
                    {
                        TreeItem<T>* toDel = node;
                        node = node->pRight;
                        delete toDel;
                        toDel = 0;
                    }
                }
            }
        }

        T findMax(TreeItem<T>*& root)
        {
            TreeItem<T>* item = root;

            while(item->pRight)
            {
                item = item->pRight;
            }

            return item->data;
        }

        T findElement(const T& value)
        {
            this->find(value,root);
        }

        T find(const T& value, TreeItem<T>*& node)
        {
            if(node)
            {
                if(value < node->data)
                {
                    this->find(value, node->pLeft);
                }

                if(value > node->data)
                {
                    this->find(value,node->pRight);
                }

                if(value == node->data)
                {
                    return node;
                }
            }
        }

};
