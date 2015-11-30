#include <iostream>
#include <string.h>
#include "LinkedStack.h"

struct repetetiveExpressionInfo // Позиции в изразите със скоби.
{
    size_t repetitionCount;
    size_t startOfExpression;
    size_t startOfString;
};

int main()
{
    std::string stringByUser;
    std::cin >> stringByUser;
    LinkedStack<repetetiveExpressionInfo> expressionStates;
    repetetiveExpressionInfo stringExpr;
    size_t stringLength = stringByUser.length();
    for(size_t i = 0; i < stringByUser.length(); i++)
    {
        if(stringByUser[i] >= '0' &&
           stringByUser[i] <= '9')
        {
            int startIndex = i;
            if(stringByUser[i+1] <= '9' && stringByUser[i+1] >= '0')
            {
                stringExpr.repetitionCount = (stringByUser[i] - '0')*10 + (stringByUser[i+1] - '0');
                i++;
            }
            else
            {
                stringExpr.repetitionCount = stringByUser[i] - '0';
            }
            i++;
            if(stringByUser[i] == '(')
            {
                stringExpr.startOfExpression = startIndex;
                stringExpr.startOfString = i + 1; // Започвам от следващия елемент
                expressionStates.push(stringExpr);
            }
        }
        else if(stringByUser[i] == ')')
        {
            stringExpr = expressionStates.top();
            expressionStates.pop();
            size_t stringLength = i - stringExpr.startOfString; // Дължина на низа
            //size_t repStringLength = stringExpr.repetitionCount * stringLength;
            std::string repString;
            std::string concatString = stringByUser.substr(stringExpr.startOfString,stringLength);
            for(int i = 0; i < stringExpr.repetitionCount ; i++)
            {
                repString += concatString;
            }
            size_t exprLength = i - stringExpr.startOfExpression + 1;
            stringByUser.replace(stringExpr.startOfExpression, exprLength,repString);
            i += repString.length() - exprLength;
        }
    }

    std::cout << stringByUser <<  std::endl;
    return 0;
}
