#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    float a=125.5;
    char *p=(char *)&a;
    printf("%d\n",*p);
    printf("%d\n",*(p+1));
    printf("%d\n",*(p+2));
    printf("%d\n",*(p+3));
    system("pause");
    return 0;
}
