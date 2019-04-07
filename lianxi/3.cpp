#include <iostream>
#include<stdio.h>
#include<vector>
#include<string.h>
#define N 1000 
using namespace std ;

class Solution
{
public :
    int col ;
    int row ;

public :
    void getnum(int row, int col, char arr[][1000])
    {
        this->row = row ;
        this->col = col ;
        int num = 0 ;
        for(int i=1;i<= row; i++)
        {
            int flag = 1 ;
            for(int j=1;j<= col; j++)
            {
                if(conti(arr))
                dfs(i,j,arr) ;
                else 
                {
                    flag = 0 ;
                }
                num ++ ;
            }
            if(flag == 0)break ;
        }
        cout << num << endl ; 
    }

    bool conti(char arr[][1000])
    {

        int flag =0 ;
        for(int i=1; i<=row ;i++)
        {
            for(int j = 1 ; j <= col ;j++)
            {
                if(arr[i][j] == '@')
                {
                    flag = 1 ;
                }
            }
        }
        return flag ;
    }

    void dfs(int i, int j,  char arr[][1000])
    {
        if(i <=0 || j<=0 || i > row || j > col || arr[i][j]=='#')
        {
            return ;
        }
        arr[i][j] = '0' ;
        dfs(i+1, j, arr) ;
        dfs(i, j+1, arr) ;
        dfs(i-1, j, arr) ;
        dfs(i, j-1, arr) ;
        dfs(i-1, j+1, arr) ;
        dfs(i-1, j-1, arr) ;
        dfs(i+1, j+1, arr) ;
        dfs(i+1, j-1, arr) ;
    }
} ;
int main()
{
    int row ;
    int col ;
    char a[N][N] ;
    cin >> row >> col ;
    
    for(int i=0;i<row+2 ;i++)
    {
        if(i == 0|| i==row+1)
        {
            memset(a[i], '0', sizeof(a[i])) ;
        }
        else 
        {
            a[i][0] = '0' ;
            gets(a[i]) ;
        }
    }
    for(int i=0;i<row+2 ;i++)
    {
        cout << a[i] <<endl ;
    }
    return 0;
}

