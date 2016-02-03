#include <iostream>
#include "include/Pair.h"
#include <cstring>
#include "include/Hash.h"
#include "include/HashTable.h"
#include <string>


int main()
{
    std::cout << "Nothing to do at the moment ! " << std::endl;

    Pair<std::string, std::string> data("Tsanislav","a1dd123mzdcdsaasasdadasasasd1231313123");
    Pair<std::string, std::string> data1("111111111111111111111111111111","ade");
    Pair<std::string, std::string> data2("122data","add12333zaa");
    Pair<std::string, std::string> data3("data31133","a1dd123mzdd");

    HashTable<std::string,std::string> tableHash;

    std::cout << std::endl;
    tableHash.addElement(data1);
    std::cout << std::endl;
    tableHash.addElement(data);
    std::cout << std::endl;
    tableHash.addElement(data2);
    std::cout << std::endl;
    tableHash.addElement(data3);

    //std::cout << "Size of data : " << sizeof(data) << "___" << data.data << std::endl;
    //std::cout << "Size of data1 : " << sizeof(data1) << "___" << data1.data << std::endl;
    //std::cout << "Size of data2 : " << sizeof(data2) << "___" << data2.data << std::endl;
    //std::cout << "Size of data3 : " << sizeof(data3) << "___" << data3.data << std::endl;

    //std::cout << "Is this real ? " << static_cast<unsigned char>(data1.data) << std::endl;

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
