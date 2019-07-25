#include<iostream>
#include<cmath>
using namespace std;

inline double CalArea(double radius)
{
    return 3.14*radius*radius;
}

int fbnc(int n)
{
    int anw;
    int num=n;
    if (num==1||num==2) anw=1; //终止条件
    else 
    anw=fbnc(num-1)+fbnc(num-2);//递归公式
    return anw;
    
}

int pwo(int n)
{
    int anw;
    if(n==0||n==1) anw=1; //终止条件
    else
    {
        anw=n*pwo(n-1);//递归公式
    }
    return anw;
    
}

int main()
{
    // int k;
    // k=fbnc(6);
    // cout<<k<<endl;
    int k;
    k=pwo(5);
    cout<<k<<endl;
    system("pause");
}