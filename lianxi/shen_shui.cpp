#include <iostream>
#include<algorithm>
using namespace std ;

int maxs = 0  ;
void dfs(int a[],int i, int len) ;
int main()
{
    int a[] = {0, 1, 8, 6, 2, 5, 4, 8, 3, 7} ;
    int len = sizeof(a)/sizeof(a[0]) ;

    for(int i=1 ; i<len; i++)
    {
        
        dfs(a, i, len) ;
    }
    cout << maxs <<endl ;
    return 0;
}

void dfs(int a[],int s , int len)
{
    for(int i = s+1;i<len;i++)
    {

        int num = min(a[s] , a[i])*abs(s-i) ;
        if(num > maxs)
        {
            maxs = num ;
        }

        dfs(a, i, len) ;
    }
}
