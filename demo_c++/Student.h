#include<string>
#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;

#ifndef _Student_dll_h_
#define _Student_dll_h_
struct Student
{
    int stuID;
    string stuName;
    float stuScore;
    Student *next;
};
Student *getStu();
bool delStuInfoByID(int );
Student *getStuInfoByID(int );
void addStudent(Student* );
bool compSocre(const Student &, const Student &);
void releaseAllStudentsInterface();
bool writeStudentsToFile(string );
bool readStudentsFromFile(string );
#endif 