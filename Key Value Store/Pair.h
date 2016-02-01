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

/*
        D getData() const
        {
            std::cout << "Get Data _" << std::endl;
            return this->data;
        }

        K getKey() const
        {
            std::cout << "Get Key _" << std::endl;
            return this->key;
        }

        void setData(D d)
        {
            std::cout << "Set Data _ "<< std::endl;
            this->data = d;
        }

        void setKey(K k)
        {
            std::cout << "Set Key _ "<< std::endl;
            this->key = k;
        }
*/
    private:
};
