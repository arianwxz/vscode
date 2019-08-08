#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
void quickSort(int s[], int l, int r)  
{  
    if(l<r)  
    {        
    int low=l;                            //左边第一个，因为第一个已经用pivot保存了  
    int high=r;                           //右边  
    int pivot = s[l];                     //第一个，已被保存  
        while(low<high)                       //当左小于右,当相等的时候会跳出循环  
        {  
            while(low<high&&s[high]>= pivot)  // 从右向左找第一个小于x的数  
                high--;   
            if(low<high)                          
                s[low++] = s[high];  
                      
            while(low<high&&s[low]<pivot)     // 从左向右找第一个大于等于x的数  
                low++;   
            if(low<high)    
                s[high--] = s[low];  
        }  
        s[low]=pivot;          
        quickSort(s, l, low - 1);             //low左边递归调用  
        quickSort(s, low + 1, r);             //low右边递归调用  
    }  
}

/* void quickSort(int s[],int l,int r)
{
    if(l<r)
    {
    int low=l;
    int high=r;
    int pivot=s[l];
    while(low<high){
    while(low<high&&s[high]>=pivot)
        high--;
    if(low<high)
        s[low++]=s[high];
    while(low<high&&s[low]<pivot)
        low++;
    if(low<high)
        s[high--]=s[low];
    }
    
    s[low]=pivot;
    quickSort(s,l,low-1);
    quickSort(s,low+1,r);
    }
} */
/* 
void quickSort(int s[],int l,int r)
{
    if(l<r)
    {
        int low=l;
        int high=r;
        int pivot=s[l];
        while (low<high)
        {
            while(low<high&&s[high]>=pivot) 
            high--;
            if(low<high)
            s[low++]=s[high];
            while(low<high&&s[low]>pivot)
            low++;
            if(low<high)
            s[high--]=s[low];    
        }
        s[low]=pivot;
        quickSort(s,l,low-1);
        quickSort(s,low+1,r);
        
    }
}
*/
void maopaoSort(int s[],int length)
{
    for (int i = 1; i < length; i++)
    {
        for (int j = 0; j < length-i; j++)
        {
            if(s[j]>s[j+1]) swap(s[j],s[j+1]);
        }
    }
}

/* void maxHeap(int a[],int n,int size)
{
    int leftchild,rightchild,largest;
    leftchild=2*n;
    rightchild=2*n+1;
    if(leftchild<=size&&a[leftchild-1]>a[n-1])
        largest=leftchild;
    else
        largest=n;
    if (rightchild<=size&&a[rightchild-1]>a[largest-1])
        largest=rightchild;
    if(largest!=n)
    {
        swap(a[n-1],a[largest-1]);
        maxHeap(a,largest,size);
    }    
    
}

void heapSort(int a[],int size)
{
    for (int i = size/2; i >0; i--)
    {
        maxHeap(a,i,size);
    }
    for (int i = size; i > 0; i--)
    {
        swap(a[0],a[i-1]);
        maxHeap(a,1,i-1);
    }
} */

void maxHeap(int a[],int n,int size)
{
    int leftchild,rightchild,largest;
    leftchild=2*n;
    rightchild=2*n+1;
    if(leftchild<=size&&a[leftchild-1]>a[n-1])
        largest=leftchild;
    else
        largest=n;
    if(rightchild<=size&&a[rightchild-1]>a[largest-1])
    largest=rightchild;
    if (largest!=n)
    {
        swap(a[largest-1],a[n-1]);
        maxHeap(a,largest,size);
    }   
}
void heapSort(int a[],int size)
{
    for(int i=size/2;i>0;i--)
    maxHeap(a,i,size);
    for (int i = size; i > 0; i--)
    {
        swap(a[0],a[i-1]);
        maxHeap(a,1,i-1);
    }
}

void merge(int a[],int b[],int l,int m,int r)
{
    int i=l;
    int j=m+1;
    int k=l;
    while (k<=r)
    {
        if(i>m){
            b[k++]=a[j++];
        }
        else if(j>r){
            b[k++]=a[i++];
        }
        else{
            if(a[i]>a[j]){
                b[k++]=a[j++];
            }
            else{
                b[k++]=a[i++];
            }
        }
    }
    for (int k = l; k <= r; k++)
    {
        a[k]=b[k];
    }
}

void mergeSortHelper(int a[],int b[],int l,int r)
{
    if(l>=r){
        return;
    }
    int m=(l+r)/2;
    mergeSortHelper(a,b,l,m);
    mergeSortHelper(a,b,m+1,r);
    merge(a,b,l,m,r);
}

void mergeSort(int a[],int len)
{
    int b[len];
    mergeSortHelper(a,b,0,len-1);
}
/* void merge(int a[], int b[], int l, int m, int r)
{
    int i = l;
    int j = m + 1;
    int k = l;
    
    while (k <= r) {
        if (i > m) {
            b[k++] = a[j++];
        }
        else if (j > r) {
            b[k++] = a[i++];
        }
        else {
            if (a[i] > a[j]) {
                b[k++] = a[j++];
            }
            else {
                b[k++] = a[i++];
            }
        }
    }

    for (int k = l; k <= r; k++) {
        a[k] = b[k];
    }
}

void merge_sort_helper(int a[], int b[], int l, int r)
{
    if (l >= r) {
        return;
    }
    int m = (l + r)/2;
    merge_sort_helper(a, b, l, m);
    merge_sort_helper(a, b, m + 1, r);
    merge(a, b, l, m, r);
}

void merge_sort(int a[], int len)
{
    int b[len];
    merge_sort_helper(a, b, 0, len - 1);
    //delete[] b;
} */

int main()
{
    int a[10]={2,3,4,5,2,3,1,6,6,7};
     quickSort(a,0,9);
    int length=sizeof(a)/sizeof(int);
    //maopaoSort(a,length);
    //heapSort(a,length);
    //mergeSort(a,length);
    for (int i = 0; i < 10; i++)
    {
        cout<<a[i]<<" ";
    }
    system("pause");
    
}