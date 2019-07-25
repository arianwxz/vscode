#include<iostream>
using namespace std;

int main()
{
    int n=4;
    int a[3][n]={1,2,3,4,5,6,7,8,9,10,11,12};
    int k;
    // int *p[n]=a;
    int (*p)[n]=a+1;
    cout<<p[0][0]/* <<" "<<*p<<" " */<<endl;
    // k=*(*(a+1)+1);
    // cout<<k<<endl;
    system("pause");
    return 0;
}