#include <iostream>

using namespace std ;

bool check(int num)
{
    int sum = 0 ;
    int a[20] ;
    int cur = 0 ;
    while(num>0)
    {
        a[cur] = num%10 ;
        sum += a[cur++] ;
        num=num/10 ;
    }

    if(sum%2 !=0)
    {
        return false ;
    }
    int t = sum/2 ;
    bool tmp[46] ={0};
    tmp[a[0]] = 1 ;

    for(int i=1; i<cur; i++)
    {
        int index = a[i] ;
        for(int j=45; j>=0; j--)
        {
            if(tmp[j] && j+index<46)
            {
                tmp[j+index] = 1 ;
            }
        }
        if(tmp[t] == 1)
        {
            return true ;
        }
    }
    return false ;
}

int main()
{
    int counts = 0 ;
    int m,n ;
    cin >> m >> n ;
    int start= clock() ;
    for(int i=m; i<=n; i++)
    {
        if(i==99871)
            getchar() ;
        if(check(i))
        {   
            cout << i <<endl ;
            counts ++ ;
        }
    }
    cout <<"神奇数的个数："<< counts << endl ;
    int end = clock() ;
    cout <<"总用时："<<end-start<<endl ;
    return 0;
}

