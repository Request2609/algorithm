#include <iostream>
using namespace std ;

void func(int x, int y)
{
    int tmp ;
    int res ;
    int flag =1 ;
    for(int i=2; i<10000; i++)
    {
        for(int j=2;j<10000;j++)
        {
            tmp = x-2*i-2*j-2 ;
            res = y-i*(i+1)-j*(j+1) ;
            
            if(tmp == res&&i<j)
            {
                printf("(%d,%d)\n", i,j) ;
                flag =0 ;
            }
        }
    }

    if(flag == 1)
    {
        cout <<"NONE" <<endl ;
    }
}

int main()
{
    
    int n ;
    cin >>n ;
    while(n--)
    {
        int x,y ;
        cin>>x>>y ;
        func(x,y) ;
    }
    return 0;
}

