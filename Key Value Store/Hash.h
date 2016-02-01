#pragma once

#include <cstring>
#include <string>

class Hash
{
    public:
        Hash();

        size_t hashFunc(std::string);

    private:
        size_t tableSize;
};


