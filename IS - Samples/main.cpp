#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class Student
{
private:
    char* name;
    int grade;

public:
    Student(char* name, int grade)
    {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name,name);
        this->grade = grade;
    }

    Student()
    {
        this->name = NULL;
        this->grade = 0;
    }

    ~Student()
    {
        delete[] this->name;
    }

    void setGrade(int grade)
    {
        this->grade = grade;
    }

    void setName(char* name)
    {
        delete[] this->name;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name,name);
    }

    friend ofstream& operator<< (ofstream& ofs, const Student st)
    {
        ofs << st.name << endl;
        ofs << st.grade << endl;

        return ofs;
    }

    friend ifstream& operator>> (ifstream& ifs, Student& st)
    {
        char* buff = new char[30];
        ifs >> buff;
        st.setName(buff);
        int tempGrade;
        ifs>> tempGrade;

        //cout << tempGrade;
        st.setGrade(tempGrade);

        delete[] buff;

        return ifs;
    }

    void print()
    {
        cout << name << endl << grade << endl;
    }
};

int main()
{
    Student st("Tsanislav_Gatev", 6);

    ofstream ofs;

    ofs.open("newFile.txt");

    ofs << st;

    ofs.close();


    ifstream ifs;

    ifs.open("newFile.txt");

    Student stNew;
    ifs >> stNew;

    ifs.close();

    stNew.print();

    return 0;
}
