#include <iostream>
#include "StringReader.h"
#include "IsIsomorphic.h"

using namespace std;

int main()
{
    std::cout << "Enter first tree : ";
    std::string tree1;
    std::cin >> tree1;
    std::cout << "\nEnter second tree : ";
    std::string tree2;
    std::cin >> tree2;
//"(0{(1{(2{(3{})(4{})(12{}))(5{(6{})(7{})))(8{(9{(10{})(11{}))(13{(14{})(15{}))))" string for test
    StringReader tree1obj(tree1);
    StringReader tree2obj(tree2);
    tree1obj.sortAllVectors();
    tree2obj.sortAllVectors();
    //test.printTree();
    //test2.printTree();

    IsIsomorphic areThey;
    if(areThey.areTheyIsomorphic(tree1obj.getTreeVector(),tree2obj.getTreeVector()))
    {
        std::cout << "YES" << std::endl;
    }
    else
    {
        std::cout << "No" << std::endl;
    }

    return 0;
}
