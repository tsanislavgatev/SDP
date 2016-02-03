#pragma once
#include <string>


template <typename D,typename K>
class Pair
{
    public:

        D data;
        K key;

        Pair()
        {
           //this->data = 0;
           //this->key = 0;
        }

        Pair(D d, K k)
        {
            this->data = d;
            this->key = k;
            this->isDeleted = false;
        }


        Pair(const Pair<D,K>& other)
        {
            this->data = other.data;
            this->key = other.key;

           // this->setData(other.getData());
            //this->setKey(other.getKey());
        }

        Pair<D,K>& operator=(const Pair<D,K>& other)
        {
            if(this != &other)
            {
                this->data = other.data;
                this->key = other.key;

                //this->setData(other.getData());
                //this->setKey(other.getKey());
            }
            return *this;
        }

        void deletePair()
        {
            this->isDeleted = true;
        }

    private:
        bool isDeleted;
};
