#include <iostream>
#include <cstring>
#include "namesDictionary.h"


int main()
{
    //std::cout << "countOfTestExamples" << std::endl;
    int countOfTestExamples = 0;
    std::cin >> countOfTestExamples;

    long long countOfStringsWithSizeEight = 0;
    long countOfCommands = 0;

    for(int i = 0; i < countOfTestExamples; i++)
    {
        do{
                std::cin >> countOfStringsWithSizeEight;
                //std::cout << "Try 1 " << i << std::endl;
        }while(countOfStringsWithSizeEight < 0 || countOfStringsWithSizeEight > 1000000);
        do{
                std::cin >> countOfCommands;
                //std::cout << "Try 2 " << i << std::endl;
        }while(countOfCommands < 0 || countOfCommands > 500000);

        namesDictionary namesOfSquirrels(countOfStringsWithSizeEight);
        namesOfSquirrels.inputWords();
        namesOfSquirrels.sortTheArray();
        for(int j = 0; j < countOfCommands; j++)
        {
            char* command = new char[14]; // дължина на на командата + интервал + максимална дължина на думата.
            //std::cout << "Command input" << std::endl;
            std::cin.clear();
            std::cin.sync();
            std::cin.getline(command,14);
            //std::cout << command << std::endl;
            if(strncmp(command,"ENTER",5) == 0)
            {
                namesOfSquirrels.setInterval(command[6] - '0',command[8] - '0');
                //std::cout << command[6] << " " << command[8] << std::endl;
            }
            else if(strncmp(command,"QUERY",5) == 0)
            {
                char* prefix = new char[9];
                char* tempP = command;
                tempP += 6;
                strcpy(prefix,tempP);
                std::cout << namesOfSquirrels.countThePrefixContainers(prefix) << std::endl;
                delete[] prefix;
            }
            else
            {
                std::cout << "Wrong command" << std::endl;
            }
            delete[] command;
        }
    }

    return 0;
}
