#include <iostream>
using namespace std ;

int main()
{
    int n ;
    int i = 0 ;
    int a[1000] ;

    cin>>n ; 
    int l = n ;
    while(l--)
    {
        cin >> a[i] ;
        i++ ;
    }

    int dist ;
    int sum = 0;
    int min_len = n+1 ;
    cin >> dist ;
    
    int j= 0,k=0 ;
    while(1)
    {
        while(j<n && sum <= dist)
        {
            sum+=a[j++] ;
        }

        if(sum < dist)
        {
            break ;
        }
        min_len = min(min_len, j-k) ;
        sum-=a[k++] ;
    }

    cout << min_len << endl ;
    return 0;
}

