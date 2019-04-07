#include <iostream>
#include<vector>
using namespace std ;
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int row_len = matrix.size() ;
        int col_len = matrix[0].size() ;
        int maxs=0 ;
    
        for(int i = 0; i < row_len; i++)
        {
            for(int j = 0; j<col_len ;j++)
            {
                int num = 0 ;
                dfs(i,j,matrix,num, maxs) ;   
            }
        }
        return maxs ;
    }

    void dfs(int i, int j, vector<vector<int>>& matrix,int num , int& maxs)
    {
        int col_len = matrix[0].size() ;
        int row_len = matrix.size() ;
        
        if(i >= row_len || j>= col_len)
        {
            return  ;
        }

        if(i == 0&&j == 0)
        {
            if(matrix[i][j] > matrix[i+1][j]) 
            {   
                num++ ;
                if(num > maxs)
                {
                    maxs = num ;
                }
                
                dfs(i+1,j, matrix,num, maxs) ;
            }
            if(matrix[i][j] > matrix[i][j+1]) 
            {   
                num++ ;
                if(num > maxs)
                {
                    maxs = num ;
                }

                dfs(i,j+1, matrix,num, maxs) ;
            }
        }

        else if(i == 0)
        {
            if(matrix[i][j] > matrix[i+1][j]) 
            {
                num++ ;
                if(num > maxs)
                {
                    maxs = num ;
                }
                dfs(i+1,j, matrix,num, maxs) ;
            }
            if(matrix[i][j] > matrix[i][j+1]) 
            {
                num++ ; 
                if(num > maxs)
                {
                    maxs = num ;
                }

                dfs(i,j+1, matrix,num, maxs) ;
            }
        }
        else if(j == 0)
        {
            if(matrix[i][j] > matrix[i][j+1])
            {
                num ++ ;
                if(num > maxs)
                {
                    maxs = num ;
                }
                dfs(i, j+1, matrix, num, maxs) ;
            }
        }
        else 
        {
            dfs()
        }
    }
};

int main()
{

    return 0;
}

