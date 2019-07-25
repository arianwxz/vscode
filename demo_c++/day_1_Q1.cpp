//#include"stdafx.h"
/*
求pi的公式 pi=16*arctan(1/5)-4*arctan(1/239)，arctanx=x-x^3/3+x^5/5....逼近的条件是单项式的值小于10^-15
 */
#include<iostream>
#include<cmath>
using namespace std;
double arctan_my(double x)
{
    int flag=1;
    double sum=0;
    for (int i = 1; pow(x,i)/i>1e-15; i+=2)
    {
        sum+=(flag*pow(x,i)/i);
        flag=-flag;
        /* code */
    }
    return sum;
}



int main(int argc, char *argv[])
{   

    cout<<16*arctan_my(1.0/5)-4*arctan_my(1.0/   239)<<endl;
    system("pause");
}