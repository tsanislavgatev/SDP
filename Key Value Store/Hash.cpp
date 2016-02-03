#include "include/Hash.h"

Hash::Hash()
{
    this->tableSize = 12289;
}

size_t Hash::hashFunc(std::string key)
{
    size_t hashVar = 0;
    size_t index = key.length();

    for(size_t i = 0; i < index; i++)
    {
        hashVar = 33 * hashVar + (int)key[i];
    }

    hashVar %= tableSize;

    return hashVar;
}

