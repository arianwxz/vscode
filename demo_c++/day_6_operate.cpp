#include<iostream>
using namespace std;

class B
{
    public:
    int bValue;
};

class  A
{
private:
    B bb[20];
public:
    A();

    B operator [](int i)
    {
        return bb[i];
    }
    ~ A();
};
A::A()
    {
        for (int i = 0; i < 20; i++)
        {
            bb[i].bValue=i;
        }
        
    }
A::~A(){}
int main()
{
    A a;
    cout<<a[5].bValue;
    system("pause");
}


