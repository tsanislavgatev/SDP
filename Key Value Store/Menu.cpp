#include "Menu.h"
#include <iostream>
#include "include/Pair.h"
#include <cstring>
#include "include/Hash.h"
#include "include/HashTable.h"
#include <string>

Menu::Menu()
{
    this->functionController();
}

void Menu::functionController()
{
    int funcIndx;
    while(true)
    {
        std::cout << "\nChose function you want to use : "
                << "\nWrite 1 if you want to store item : "
                << "\nWrite 2 if you want to load items data : "
                << "\nWrite 3 if you want to delete item : "
                << "\nWrite 4 if you want to close the program : " << std::endl;
        std::cin >> funcIndx;
        if(funcIndx == 1)
        {
            std::string data;
            std::string key;
            std::cout << "Enter a data : " ;
            std::cin >> data;
            std::cout << "\nEnter a key (only with numbers and letters) : ";
            std::cin >> key;
            std::cout << std::endl;
            Pair<std::string, std::string> pairToStore(data,key);
            tableHash.addElement(pairToStore);
        }
        else if(funcIndx == 2)
        {
            std::cout << "\nWrite the key of the item you want to load : ";
            std::string key;
            std::cin >> key;
            tableHash.findElementWithKey(key);
        }
        else if(funcIndx == 3)
        {
            std::cout << "\nWrite the key of the item you want to delete : ";
            std::string key;
            std::cin >> key;
            tableHash.deleteElementWithKey(key);
        }
        else if(funcIndx == 4)
        {
            std::cout << "\n\nHave a nice day  : ) " << std::endl;

            break;
        }
        else
        {
            std::cerr << "Wrong Index !";
        }
    }
}
