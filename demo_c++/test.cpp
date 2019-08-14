#include<iostream>
#include<thread>
#include <chrono>
using namespace std;

int main()
{
    int a[4]={1,2,3,4};
    for (auto b:a)
    {
        cout<<b<<" ";
    }
    system("pause");
    
}
