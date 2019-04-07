#include <iostream>
using namespace std ;

int main()
{
    int a,b,c ;
    cin>>a>>b>>c ;
    int maxs ;
    maxs = max(a,b) ;
    maxs = max(maxs, c) ;
    int i = 1 ;
    while(1)
    {
        if(maxs%a==0&&maxs%b==0&&maxs%c==0)
        {
            cout << maxs <<endl ;
            break ;
        }
        cout << "-----" <<endl ;
        maxs = maxs*(++i) ;
    }
    return 0;
}

