#include <iostream>
#include "include/Pair.h"
#include <cstring>
#include "include/Hash.h"
#include "include/HashTable.h"


int main()
{
    std::cout << "Nothing to do at the moment ! " << std::endl;

    Pair<int, std::string> data(1110,"a1dd123mzdcdsaasasdadasasasd1231313123");
    Pair<int, std::string> data1(1111,"ade3mzdb2");
    Pair<int, std::string> data2(1112,"add12333zaa");
    Pair<int, std::string> data3(1113,"a1dd123mzdd");

    HashTable<int,std::string> tableHash;

    std::cout << std::endl;
    tableHash.addElement(data1);
    std::cout << std::endl;
    tableHash.addElement(data);
    std::cout << std::endl;
    tableHash.addElement(data2);
    std::cout << std::endl;
    tableHash.addElement(data3);

    tableHash.findElementWithKey("a1dd123mzdd");

    //std::cout << data.getData() << "   __   "  << data.getKey() << std::endl;

    //Hash obj;

    //std::cout << "Hash code : " << obj.hashFunc(data.getKey()) << std::endl;
    //std::cout << "Hash code : " << obj.hashFunc(data1.getKey()) << std::endl;
    //std::cout << "Hash code : " << obj.hashFunc(data2.getKey()) << std::endl;
    //std::cout << "Hash code : " << obj.hashFunc(data3.getKey()) << std::endl;
    //std::cout << obj.hashFunc(data.getKey()) << std::endl;

    return 0;
}
