#include <iostream>
#include<vector>
#include<queue>
#include<memory>
#define N 10000

using namespace std ;
class node ;

class Solution {
public:
    int col, row ;
    void dfs(int& flag, int i, int j, int step, int& min_step, vector<vector<int>>& matrix, int a[][1000])
    {
        if(matrix[i][j] == 0||i == col-1||j==row-1)
        {   
            return ;
        }
        a[i][j] = 1 ;

        if(i+1<row&&a[i+1][j]==0&&matrix[i+1][j]!=0)
        {
            flag =1 ;
            step++ ;
            if(step >min_step)
            {
                min_step = step ;
            }
            dfs(flag, i+1, j, step, min_step, matrix, a) ;
            step-- ;
        }
        
        if(j+1<col&&a[i][j+1]==0&&matrix[i][j+1]!=0)
        {
            flag  =1  ;
            step++ ;
            if(step >min_step)
            {
                min_step = step ;
            }
            dfs(flag, i, j+1, step, min_step, matrix, a) ;
            step -- ;
        }

        if(i-1>=0&&a[i-1][j]==0&&matrix[i-1][j]!=0)
        {
            flag =1 ;
            step++ ;
            if(step >min_step)
            {
                min_step = step ;
            }
            dfs(flag, i-1, j, step, min_step, matrix, a) ;
            step-- ;
        }

        if(j-1>=0&&a[i][j-1]&&matrix[i][j-1]!=0)
        {
            flag =1  ;
            step++ ;
            if(step >min_step)
            {
                min_step = step ;
            }
            dfs(flag,i, j-1, step, min_step, matrix, a) ;
            step-- ;
        }
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) 
    {
        row = matrix.size();
        col = matrix[0].size();
        int step = 0 ; 
        for(int i=0;i<row ;i++)
        {
            for(int j=0;j<col;j++)
            {
                int flag  = 0 ;

                if(matrix[i][j] != 0)
                {
                    int a[1000][1000]={{0}} ;
                    
                    int min_step = 1;
                    dfs(flag, i, j,step, min_step, matrix, a) ;
                    if(flag == 1)
                    matrix[i][j] = min_step+1;
                }
            }
        }
        return matrix ;
    }
};
int main()
{
    vector<vector<int>>ls ;
    for(int i=0;i<3;i++)
    {
        vector<int>s ;
        for(int j=0;j<3;j++)
        {
            int a ;
            cin>> a ;
            s.push_back(a) ;
        }
        ls.push_back(s) ;
    }
    for(size_t i=0;i<ls.size(); i++)
    {
        for(size_t j=0;j< ls[0].size();j++)
        {
            cout << ls[i][j] <<"   " ;
        }
        cout <<endl ;
    }
    Solution ss ;
    vector<vector<int>>ll = ss.updateMatrix(ls) ;
    for(size_t i=0;i<ll.size(); i++)
    {
        for(size_t j=0;j< ll[0].size();j++)
        {
            cout << ll[i][j] <<"   " ;
        }
        cout <<endl ;
    }
    return 0;
}

