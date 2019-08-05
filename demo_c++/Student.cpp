#include"Student.h"

Student *Head=NULL;
int LISTLEN=0;
Student *getStu()
{
    return Head;
}
//通过学号删除学生信息,未找到学号，提示删除失败
bool delStuInfoByID(int stuID)
{
    Student *p=Head;
    Student *pbef;
    if(Head->stuID==stuID)
    {
        Head=Head->next;
        delete p;
        return true;
    }
    else
    {
        pbef=Head;
        p=Head->next;
        while (p!=NULL)
        {
            if(p->stuID==stuID)
            {
                pbef->next=p->next;
                delete p;
                return true;
            }
            p=p->next;
            pbef=pbef->next;
        }
        return false;
    }
}
//通过学号查询学生信息
Student *getStuInfoByID(int stuID)
{
    Student *p=Head;
    while (p!=NULL)
    {
        if(p->stuID==stuID)
        return p;
        p=p->next;
    }
    return NULL;
}
//添加学生信息
void addStudent(Student* Studentinfo)
{
    if (Head==NULL)
    {
        Head=Studentinfo;
    }
    else
    {
        Studentinfo->next=Head;
        Head=Studentinfo;
    }
    LISTLEN++;
}
bool compSocre(const Student &stu1, const Student &stu2)
{
    return stu1.stuScore<stu2.stuScore;
}

//释放指针
void releaseAllStudentsInterface()
{
    Student *p=Head;
    while (p!=NULL)
    {
        Student *tmp=p;
        p=p->next;
        delete tmp;
    }    
}

//向文件写入学生信息
bool writeStudentsToFile(string fileName)
{
    FILE *fp;
    if((fp=fopen(fileName.data(),"wb+"))==NULL)
    return false;
    fwrite(&LISTLEN,sizeof(int),1,fp);//写入链表总数
    Student*p=Head;
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

//从文件读出学生信息
bool readStudentsFromFile(string fileName)
{
    releaseAllStudentsInterface();
    Head=NULL;
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
        addStudent(p);
    }
    fclose(fp);
    return true;  
}