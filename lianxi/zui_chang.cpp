#include <iostream>
#include<vector>
#define N 10000
int arr[N][N] ;
int tmp_arr[N][N]  ;
int col_len ;
int row_len ;

using namespace std ;
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
              
        row_len = matrix.size() ;
        col_len = matrix[0].size() ;
            
        for(int i=0; i<=row_len+1; i++)
        {
            for(int j=0; j<=col_len+1; j++)
            {
                if(i == 0||j == 0||i ==row_len+1||col_len+1==j)
                {
                    arr[i][j] = -1 ;
                    tmp_arr[i][j]=-1  ;
                }
                else
                {
                    arr[i][j] = 0 ;
                    tmp_arr[i][j] = matrix[i-1][j-1] ;
                }
            }
        }   
        int num = 1;
        int maxs = 1 ;
        for(int i=1;i <= row_len;i++)
        {
            for(int j=1;j<= col_len;j++)
            {
                dfs(i,j,num, maxs) ;
            }   
        }
        return maxs;
    }
    void dfs(int i, int j, int num, int maxs)
    {
         if(i <= 0||j <= 0|| i>row_len||j>col_len || tmp_arr[i][j] == 1) 
         {
            return ;
         }
         //标记这个点走过
        tmp_arr[i][j] = 1 ;
        if(j+1<col_len&&arr[i][j] > arr[i][j+1])
        {
            num ++ ;
            if(num > maxs)
            {
                maxs = num ;
            }

            dfs(i, j+1, num, maxs) ;
            num-- ;
            tmp_arr[i][j] = 0 ;
        }

        if(i+1<row_len&&arr[i][j] > arr[i+1][j])
        {
            num++ ;
            if(num > maxs)
            {   
                maxs = num ;
            }
            dfs(i+1, j, num, maxs) ;
            tmp_arr[i][j] = 0 ;
            num-- ;
        }
        
        if(i-1 != 0&&tmp_arr[i][j]!=1&&arr[i][j] > arr[i-1][j])
        {
            num++ ;
            if(num > maxs)
            {
                maxs = num ;
            }
            dfs(i-1, j, num, maxs) ;
            tmp_arr[i][j] = 0 ;
            num-- ;
        }
    
        if(j-1 != 0&&tmp_arr[i][j-1]!=1&&arr[i][j] > arr[i][j-1])
        {
            num++ ;
            if(num > maxs)
            {
                maxs = num ;
            }
            dfs(i, j-1, num, maxs) ;
            tmp_arr[i][j] = 0 ;
            num -- ;
        }
    }
};
int main()
{
    vector<vector<int>>arr ;
    int a ;
    for(int i=0;i<3;i++)
    {
        vector<int>a1 ;
        for(int j=0;j<3;j++)
        {
            cin >> a ;
            if(a == -1)break ;
            a1.push_back(a) ;
        }
        arr.push_back(a1) ;
    }
    Solution s ;
    cout << s.longestIncreasingPath(arr) <<endl ;
    return 0;
}

