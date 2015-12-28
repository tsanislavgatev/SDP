#pragma once

class namesDictionary
{
    public:
        namesDictionary();//
        namesDictionary(long long);//
        ~namesDictionary();//
        namesDictionary(const namesDictionary& other);//
        namesDictionary& operator=(const namesDictionary& other);//

    private:
        char** dictionary;//
        long long countOfNames;//
        int intervalBegin;//
        int intervalEnd;//
        int prefixCounter;
        int length;

    public:
        char** getDictionary(); //
        void inputWords();//
        int countThePrefixContainers(char*);
        void printArray();//
        void setInterval(int, int);//
        void sortTheArray();//

    private:
        void mergeArr(int, int, int);//
        void mergeSortArr(int, int);//

        //void copyArray(const namesDictionary&);
        void destroyArray();//

};


