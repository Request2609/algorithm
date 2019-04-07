#include <iostream>
#include<vector>
using namespace std ;
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix)
    {
        int row = matrix.size() ;
        int col = matrix[0].size() ;
        vector<vector<int>>a(row, vector<int>(col, 1000)) ;
        for(int i=0; i<row; i++)
        {
            for(int j=0;j<col; j++)
            {
                if(matrix[i][j] == 0)
                {
                    a[i][j] = 0 ;
                }
                else
                {
                    if(i>0)
                    {
                        a[i][j] = min(a[i][j], a[i-1][j]+1) ;
                    }
                    if(j>0)
                    {
                        a[i][j] = min(a[i][j], a[i][j-1]+1) ;
                    }
                }
            }
        }

        for(int i = row-1;i>=0; i--)
        {
            for(int j= col-1; j>=0; j--)
            {
                if(i<row-1)
                {
                    a[i][j] = min(a[i][j],a[i+1][j]+1) ;
                }
                if(j<col-1)
                {
                    a[i][j] = min(a[i][j], a[i][j+1]+1);
                }
            }
        }
        return a ;
    }
};
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

