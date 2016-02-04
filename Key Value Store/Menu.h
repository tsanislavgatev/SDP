#pragma once

#include "HashTable.h"
#include <string>

class Menu
{
    public:
        Menu();

    private:
        HashTable<std::string,std::string> tableHash;

    private:
        void functionController();
        void storeItem();
        void deleteItem();
        void findItem();
};

