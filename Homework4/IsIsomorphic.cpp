#include "IsIsomorphic.h"

IsIsomorphic::IsIsomorphic()
{

}

bool IsIsomorphic::areTheyIsomorphic(std::vector<std::vector<size_t> > first, std::vector<std::vector<size_t> > second)
{
    if(first.size() != second.size())
    {
        return false;
    }

    size_t length = first.size();

    for(size_t i = 0; i < length; i++)
    {
        int j = 0;
        while(first[i].size() > j && second[i].size() > j)
        {
            if(first[first[i][j]].size() != second[second[i][j]].size())
            {
                return false;
            }
            j++;
        }
    }


    return true;
}
