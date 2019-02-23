#include <iostream>
#include<string.h>
using namespace std ;

#define N 100 

/*
 *将多叉树转化成括号表示法
 *        A
 *        |
 *  ------------- 
 *  B   C       D
 *      |       |
 *   -------    - 
 *   E     F    G
 *  #
 *  (A(B()C(E()F())D(G())))
 * */
char buf[N+10][N+10] ;
int n ;

void dfs( int r, int c )
{
    cout<<buf[r][c]<<"(";
    if( r+1 < n && buf[r+1][c] == '|' )
    {
        int i = c ;
        while( i-1 >= 0 && buf[r+2][i-1] == '-' ) i-- ;
        while( buf[r+2][i] == '-' && buf[r+3][i] != '\0')
        {
            if(!isspace(buf[r+3][i])) dfs( r+3 , i ) ;
            i++ ;
        }
    }
    cout<<")" ;
}

void solve()
{
    n = 0 ;
    
    for( ; ; )
    {
        fgets( buf[n], N, stdin ) ;
        if( buf[n][0] == '#' ) break ;
        else n++ ;
    }

    cout << "(" ;
    for( unsigned int i = 0; i < strlen(buf[0]); i++ )
    {
        if( buf[0][i] != ' ' )
        {
            dfs( 0, i ) ;
            break ;
        }

    }
    cout<<")\n";
}


int main()
{
    
    int T ;
    fgets( buf[0], N, stdin ) ;
    sscanf( buf[0], "%d" ,&T ) ;

    while(T--)solve() ;
    return 0;
}

