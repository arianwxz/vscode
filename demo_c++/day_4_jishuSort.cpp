#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

#define POS 4
vector<vector<int>> vs(10,vector<int>());
int getNumPos(int num,int pos)
{
    int res;
    int temp=1;
    for (int i = 0; i < pos-1; i++)
    {
        temp*=10;
    }
    res=(num/temp)%10;
    return res;
}

void showNum(vector<int> v)
{
    for(int i=0;i<v.size();i++)
    cout<<v[i]<<" ";
}

vector<int> JishuSort(vector <int> v)
{
    int temp;
    int length=v.size();
    vector<int> res;
    for(int k=1;k<=POS;k++)
    {
        for (int i = 0; i < length; i++)
        {
            temp=getNumPos(v[i],k);
            vs[temp].push_back(v[i]);
        }
        int flag=0;
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<vs[i].size();j++)
            {
                v[flag]=vs[i][j];
                flag++;
            }
            vs[i].clear();
        }
        
    }
    for(int i=0;i<length;i++)
    {
        res.push_back(v[i]);
    }
    return res;
}

int main()
{
    int temp;
    vector<int> num;
    while (cin>>temp)
    {
        num.push_back(temp);
        if(cin.get()=='\n') break;
        
    }
    num=JishuSort(num);
    for(int i=0;i<num.size();i++)
    {
        cout<<num[i]<<" ";
    }
    cout<<endl;
    system("pause");
}