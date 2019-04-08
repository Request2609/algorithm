#include <iostream>
using namespace std ;

void solve(int& counts, int n)
{
    if(n == 1)
    {
        counts++ ;
    }

    else
    {
        for(int i=2; i<=n; i++)
        {
            if(n%i == 0)
            {
                solve(counts, n/i) ;
            }
        }
    }
}

int main()
{
    
    int n ;
        
    cin >> n ;
    int counts=0 ;
    solve(counts, n) ;
    cout << counts << endl ;
    return 0;
}

