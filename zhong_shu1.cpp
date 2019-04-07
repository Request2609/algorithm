#include <iostream>
#include<vector>
#include<algorithm>
using namespace std ;


vector<int>shu ;
vector<int>liang ;
int num ;
int cnt ;
int maxnum = 0;
void process(int*arr, int& mid, int n) ;
void getIndex(int*arr, int n, int& l, int& r) ;

int main()
{

    int k = 0 ;


    vector<int>a ;
    int ss ;
    while(1)
    {
        cin >>ss ;
        if(ss == -1)break ;
        a.push_back(ss) ;

    }
    sort(a.begin(), a.end()) ;
    int* arr = new int[a.size()] ;
    
    for(size_t i =0 ;i<a.size();i++)
    {
        arr[i] = a[i] ;
    }

    int len = a.size() ;
    process(arr, k, len);
    for(size_t i= 0;i<shu.size();i++)
    {
        cout << shu[i] <<"   "<<liang[i] <<endl ;
    }
    free(arr) ;
    return 0;
}

void process(int*arr, int& mid, int n )
{
    int l=0, r=0 ;
    //计算最中间的数出现的次数
    getIndex(arr, n, l, r) ;
    int cnt = r-l ;
    int m = n/2 ;
    int num = arr[m] ;
    if(cnt >= maxnum)
    {
        if(!shu.size())
        {
            shu.push_back(num) ;
            liang.push_back(cnt) ;   
        }

        else if(maxnum == cnt&& num != shu[0])
        {
            shu.push_back(num) ;
            liang.push_back(cnt) ;
        }

        if(cnt > maxnum)
        {
            vector<int>shu_tmp ;
            vector<int>liang_tmp ;
            shu_tmp.push_back(num) ;
            liang_tmp.push_back(cnt) ;
            shu = shu_tmp ;
            liang = liang_tmp ;
        }

        maxnum = cnt ;
        mid = num ;
    }

    if(l+1 > maxnum)
    {
        process(arr, mid, l+1);
    }

    if(n-r > maxnum)
    {
        process(arr+r, mid, n-r) ;
    }
}

void getIndex(int*arr, int n, int& l, int& r) 
{

    for(l = 0; l< n; l++)
    {
        if(arr[l] == arr[n/2])
        {
            break ;
        }
    }

    for(r = l+1; r <n; r++)
    {
        if(arr[r] != arr[n/2])
        {
            break ;
        }
    }
}
