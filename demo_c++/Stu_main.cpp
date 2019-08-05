#include"Stu_main.h"
#include<iostream>
#include<vector>
#include<string>

#define STUFILE stu.data
using namespace std;

void init()
{
    readStudentsFromFile(STUFILE);
}

//输出所有学生，降序排列
void printAllStudentsInfo()
{
    vector<Student> vStu;
    Student *p=getHead();
    while (p!=NULL)
    {
        
        vStu.push_back(*p);
        p=p->next;
    }   
    sort(vStu.begin(),vStu.end(),compSocre);
    for (int i = 0; i < vStu.size(); i++)
    {
        cout<<"学号"<<vStu[i].stuID<<"  "<<"姓名"<<vStu[i].stuName<<"  "<<"成绩"<<vStu[i].stuScore<<endl;
    }
}

void addStu()
{
    string inputStr;
    do{
        Student *newStu=new Student;
        newStu->next=NULL;
        cout<<"请输入学生ID: ";
        cin>>newStu->stuID;
        cout<<endl;
        cout<<"请输入学生姓名：";
        cin>>newStu->stuName;
        cout<<endl;
        cout<<"请输入学生成绩: ";
        cin>>newStu->stuScore;
        cout<<endl;
        cout<<"继续添加请输入Y,按任意键退出：";
        cin>>inputStr;
        addStudent(newStu);
    }while (inputStr=="Y");

    if(writeStudentsToFile(STUFILE))
    {
        cout<<"添加信息成功！"<<endl;
    }
    else
    {
        cout<<"添加信息失败！"<<endl;
    }   
}

void searchStu()
{
    int stuID;
    cout<<"请输入要查询学生的ID："；
    cin>>stuID;
    Student *stu;
    stu=getStuInfoByID(stuID);
    if (stu==NULL)
    {
        cout<<"未查到学生信息"<<endl;
    }
    else
    {
        cout<<"学号"<<stu->stuID<<"  "<<"姓名"<<stu->stuName<<"  "<<"成绩"<<stu->stuScore<<endl;
    }
}

void delStu()
{
    int stuID;
    cout<<"请输入要删除学生的ID："；
    cin>>stuID;
    if(delStuInfoByID(stuID))
    {
        cout<<"删除成功!"<<endl;
    }
    else
    {
        cout<<"删除失败!"<<endl;
    }
    writeStudentsToFile(STUFILE);
}

void showMainOperation()
{
    string inputStr;//操作编号
    int oid;
    do
    {
        cout<<"-------------主菜单-------------"<<endl;
        cout<<"     "<<"1.显示所有学生信息"<<endl;
        cout<<"     "<<"2.添加学生信息"<<endl;
        cout<<"     "<<"3.根据学号查询学生信息"<<endl;
        cout<<"     "<<"4.根据学号删除学生信息"<<endl;
        cout<<"     "<<"5.退出程序"<<endl;
        cout<<endl;
        cout<<"请输入操作编号:"<<" ";
        cin>>inputStr;
        
        try {
            oid=stoi(inputStr);
            }
        catch (std::invalid_argument&){
                cout<<endl;
                cout << "输入不合法，请重新输入!" << endl;
                cout<<endl;
                continue;
            }
        switch (oid)
        {
        case 1:
            printAllStudentsInfo();
            break;
        case 2:
            addStu();
            break;
        case 3:
            searchStu();
            break;
        case 4:
            delStu();
            break;
        case 5:
            /* code */
            break;      
        default:
            cout<<endl;
            cout<<"输入有误，请输入正确编号!"<<endl;
            cout<<endl;
            break;
        }
    } while (oid!=5);
    cout<<"     "<<"程序已退出"<<endl;
}

void exitProgram()
{
    writeStudentsToFile(STUFILE);
    releaseAllStudentsInterface();
}

int main()
{
    init();
    showMainOperation();
    exitProgram();
    system("pause");
    return 0;
}