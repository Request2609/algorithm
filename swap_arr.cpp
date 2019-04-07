#include <iostream>
#include<vector>
using namespace std ;
void process(int*arr, int l, int len) ;
void equal_swap(int *arr, int len) ;

int main()
{
    vector<int>a ;

    int num ;
    while(1)
    {
        cin>> num ;
        if(num == -1)break ;
        a.push_back(num) ;
    }

    size_t len = a.size() ;
    int *arr=new int[len+1] ;
    
    for(size_t i =0 ;i<len ;i++)
    {
        arr[i] = a[i] ;
    }
    
    int l = 0 ;
    cin >> l ;
    process(arr, l, len) ;
    free(arr) ;
    return 0;
}

void process(int* arr, int l, int len)
{
    int mid = len/2 ;
    //特殊情况左边元素数量恰好等于右边元素数量
    if(len%2 == 0 && l == len/2)
    {
        equal_swap(arr, len) ;
        return  ;
    }
}

void equal_swap(int* arr, int len)
{
    int tmp ;
    int mid = len/2 ;
    for(int i=0;i< mid; i++)
    {
        tmp = arr[i] ;
        arr[i] = arr[mid+i] ;
        arr[mid+i] = tmp ;
    }
}
