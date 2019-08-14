#include<iostream>
using namespace std;
template<class T>
class CMyList
{
private:
    T *head;
    int total_len;
    int fact_len;
public:
    typedef bool(*LCOMPARE)(T &a,T &b);
    CMyList();
    ~CMyList();
    void AddTail(T val);
    bool DelStu(int val);
    void Sort(LCOMPARE comp);
    T operator [](int );
    CMyList<T>& operator =(CMyList<T>& );
    CMyList<T>(const CMyList<T> &);
};

template<class T>
void CMyList<T>::Sort(LCOMPARE comp)
{
    for (int i = 0; i < this->fact_len; i++)
    {
        for (int j = 0; j < this->fact_len-i; j++)
        {
            if (comp(head[j],head[j+1]))
            {
                T t=head[j];
                head[j]=head[j+1];
                head[j+1]=t;
            }
            
        }
        
    }
    
}

template<class T>
void CMyList<T>::AddTail(T val)
{
    if(fact_len==total_len)
        {
            total_len=2*total_len;
            T* temp=new T[total_len];
            memcpy(temp,head,fact_len); //将之前的拷贝到新的空数组
            delete []head;
            head=temp;
            head[fact_len++]=val;
        }
        else
        {
            head[fact_len++]=val;
        }
}

template<class T>
bool CMyList<T>::DelStu(int val)
{
    for (int i = 0; i < this->fact_len; i++)
    {
        if(head[i]==val) 
        {
            for (int k = i+1; k < fact_len; k++)
            {
                head[k-1]=head[k];
            }
            fact_len--;
            return true;
        }
        else
        {
            return false;
        }
        
        
    }
    
}

template<class T>
T CMyList<T>::operator [](int i)
    {
        if(i<fact_len)
        {
            return head[i];
        }
        else
        {
            throw -1;
        }
        
    }


template<class T>
CMyList<T>& CMyList<T>::operator =(CMyList<T> &val)
{
    if(this->head==NULL)
    {
        this->head=new T;
    }
    *(this->head)=*(val.head);
    this->total_len=val.total_len;
    this->fact_len=val.fact_len;
    return *this;
}

template<class T>
CMyList<T>::CMyList(const CMyList<T> &val){
    this->head=new T(*val.head);
    this->total_len=val.total_len;
    this->fact_len=val.fact_len;
}

template<class T>
CMyList<T>::CMyList()
{
    fact_len=0;
    total_len=10;
    head=new T[total_len];
}

template<class T>
CMyList<T>::~CMyList()
{
    if(head!=NULL){
        delete []head; 
    }
}



/* template<class T>
class MyList
{
private:
    T *a;
    int fact;
    int total_len;
public:
    MyList(){
        fact=0;
        total_len=10;
        a=new T[total_len];
    }
    void Add(T value)
    {
        if(fact==total_len)
        {
            total_len=2*total_len;
            T* temp=new T[total_len];
            memcpy(temp,a,fact); //将之前的拷贝到新的空数组
            delete []a;
            a=temp;
            a[fact]=value;
        }
        else
        {
            a[fact++]=value;
        }
        
    }
    ~MyList(){
        if(head!=NULL){
            delete []head; 
        }
    }
}; */


/* template <class T>
CMyList<T>::~CMyList()
{
    if(head!=NULL){
        delete []head;
    }
} */
/* 
int main()
{
    A a(10);
    A b(20);
    A c(10);
    c=a+b;
    cout<<*c.value;
    system("pause");
} */