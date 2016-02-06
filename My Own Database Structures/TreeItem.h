#pragma once

template <typename T>
class TreeItem
{
    public:
        TreeItem()
        {
            data = 0;
            pLeft = 0;
            pRight = 0;
        }

        TreeItem<T>* pLeft;
        TreeItem<T>* pRight;
        T data;
};
