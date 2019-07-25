    #include<Windows.h>  //句柄==ID号
    #include<iostream>
    #include<tchar.h> //2015版本之前找不到_T
    using namespace std;
    
    typedef int(*pfnAdd)(int,int);//存储类关键字 
    //表示定义别名 表示参数为(int int)
    //返回值为int的函数Q都可以用pfnAdd 定义的对象 
    //指向函数Q
    int main()
    {
        // 1.加载
        HINSTANCE dllHandle=LoadLibrary(_T("H:\\C_PROJECT\\DLLTEST\\Debug\\DLLTEST.dll"));
        //查找顺序 在工程同目录查找->system32查找->path路径查找  
        //_T是将原本的多字节编码转换成Unicode编码
        //Win32DLL.dll是制作的dll的位置 H:\\XXX\\TESTDLL.dll
        if(NULL==dllHandle)
        {
            cout<<"Load all failed"<<endl;
            return -1;
        }
        // 2.获取函数指针，做函数调用
        pfnAdd f=(pfnAdd)GetProcAddress(dllHandle,"add");
        //typedef定义的函数类型定义一个对象，对象是一个函数指针f
        //指向获取到的同类型的dll里面的add函数 地址     
        if(NULL==f)
        {
            cout<<"Uable find add function!"<<endl;
        }
        else
        {
            cout<<"Result:"<<f(3,5)<<endl;
        }
        // 3.释放dll
        FreeLibrary(dllHandle);
        system("pause");
        return 0;
    }