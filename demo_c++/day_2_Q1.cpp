//汉诺塔 递归
#include<iostream>
using namespace std;

int hannuo(int n)
{
    if(n<=0) 
    {
        cout<<"input error"<<endl;
        return 0;
    }
    int res;
    if(n==1) res=1;
    else
    {
        res=2*hannuo(n-1)+1;
    }
    return res;
    
}

int main()
{
    int hannuo_num;
    cin>>hannuo_num;
    int res;
    res=hannuo(hannuo_num);
    cout<<"operation times:"<<res<<endl;
    system("pause");
}