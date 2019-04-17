#include <iostream>
#include<vector>
#include<algorithm>
using namespace std ;
#define N 100 
bool check(int num)
{
    if(num < 10)
    {
        return false ;
    }
    
    else if(num<100)
    {
        if(num%10 == num/10){
            return true ;
        }
        else return false ;
    }
    

    vector<int>ls ;
    int i = 0 ;
    int sum = 0 ;
    while(num>0)
    {
        int tmp = num%10 ;
        
        ls.push_back(tmp);
        sum+=tmp ;
        i++ ;
        num/=10 ;
    }
    if(sum%2 != 0)return false ;
    sort(ls.begin(), ls.end()) ;
    sum =  0 ;
    int l= 0;
    int r = ls.size()-1 ;
    int sum_cmp = ls[r];

    while(1)
    {
        while(l<r)  
        {
            sum += ls[l++] ;
            if(sum >= sum_cmp)
            {
                break ;
            }
        }

        while(r>l)
        {
            sum_cmp += ls[r--] ;
            if(sum_cmp >= sum)
            {
                break ;
            }
        }

        if(r <= l)
            break ;
    }
    if(sum_cmp != sum)
    {
        return false ;
    }

    return true ;
}

int main()
{
    int l, r ;
    cin>>l>>r ;
    int counts=0 ;
    double start = clock() ;
    for(int i=l; i<=r; i++)
    {
        if(check(i))
        {
            counts++ ;
            cout << i <<endl ;
        }
    }
    double end = clock() ;
    cout << counts <<endl ;
    cout <<"程序运行时间:"<<start-end<<endl ;
    return 0;
}

