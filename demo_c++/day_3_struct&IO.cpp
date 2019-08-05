#include<iostream>
#include<string>
#include<stdio.h>
#pragma pack(1)

using namespace std;
struct Student

{     
    int stuID;
    string stuName;
    float stuScore;
    Student *next;
    /* data */
};
// Student *Head=new Student();
//new Student()方法 head为头指针，多一个
Student *Head=new Student();
int LISTLEN=0;
void addStudent(Student* Studentinfo)
{
    if (Head->next==NULL)
    {
        Head->next=Studentinfo;
    }
    else
    {
        Studentinfo->next=Head->next;
        Head->next=Studentinfo;
    }
    LISTLEN++;
    
    
}
//head为第一个指针本身,不用多加一个空头
Student *Head1=NULL;
void addStudent1(Student* Studentinfo)
{
    if (Head1==NULL)
    {
        Head1=Studentinfo;
    }
    else
    {
        Studentinfo->next=Head1;
        Head1=Studentinfo;
    }
    LISTLEN++;
    
    
}
//打印所有学生
void PrintAllStudentsInterface()
{
    Student *p=Head1;
    while (p!=NULL)
    {
        cout<<"学生ID"<<p->stuID<<"学生姓名"<<p->stuName<<"学生成绩"<<p->stuScore<<endl;
        p=p->next;
    }   
}
//释放所有指针
void ReleaseAllStudentsInterface()
{
    Student *p=Head1;
    while (p!=NULL)
    {
        Student *tmp=p;
        p=p->next;
        delete tmp;
    }    
}

bool WriteStudentsToFile(string fileName)
{
    FILE *fp;
    if((fp=fopen(fileName.data(),"wb+"))==NULL)
    return false;

    fwrite(&LISTLEN,sizeof(int),1,fp);//写入链表总数
    Student*p=Head1;
    for (int i = 0; i < LISTLEN; i++)
    {
        fwrite(&p->stuID,sizeof(int),1,fp);//stuID
        fwrite(&p->stuScore,sizeof(float),1,fp);
        int nameLen=p->stuName.length()+1;//string长度
        fwrite(&nameLen,sizeof(int),1,fp);
        fputs(p->stuName.data(),fp);//写出具体字符串，因为是二进制流，所以写入字符串要用fputs, string.data()
        p=p->next;
    }

    fclose(fp);
    return true;
}

bool ReadStudentsFromFile(string fileName)
{
    ReleaseAllStudentsInterface();
    Head1=NULL;
    LISTLEN=0;
    FILE *fp;
    if (NULL==(fp=fopen(fileName.data(),"rb")))
    {
        return false;
    }
    int listsize;
    fread(&listsize,sizeof(int),1,fp);
    for (int i = 0; i < listsize; i++)
    {
        Student *p=new Student;
        fread(&p->stuID,sizeof(int),1,fp);
        fread(&p->stuScore,sizeof(float),1,fp);
        int nameLen;
        fread(&nameLen,sizeof(int),1,fp);
        char *tempstr=new char[nameLen];
        fgets(tempstr,nameLen,fp);
        string tempstring(tempstr);
        p->stuName=tempstring;
        p->next=NULL;
        delete []tempstr;
        addStudent1(p);
    }

    fclose(fp);
    return true;  
}


int main()
{
    // Head->next=NULL;
    string inputstr;
    do
    {
        Student *stu=new Student();
        stu->next=NULL;
        cout<<"-----AddStudent-----"<<endl;
        cout<<"输入学生ID"<<endl;
        cin>>stu->stuID;
        cout<<"输入学生名字"<<endl;
        cin>>stu->stuName;
        cout<<"输入学生分数"<<endl;
        cin>>stu->stuScore;
        stu->next=NULL;
        addStudent1(stu);
        cout<<"继续输入请输入Y"<<endl;
        cin>>inputstr;
    } while (inputstr=="Y");
    
    WriteStudentsToFile("a.txt");

    ReadStudentsFromFile("a.txt");
    PrintAllStudentsInterface();
   // cout<<"学生人数："<<LISTLEN<<endl;
    system("pause");

    
};