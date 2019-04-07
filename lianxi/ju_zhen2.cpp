#include <iostream>
#include<vector>
#include<queue>
using namespace std; 

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix)
    {   
        vector<vector<int>>res(matrix.size(), vector<int>(1000,0));
        int row = matrix.size() ;

        if(row == 0)
        {
            res.clear() ;
            return res ;
        }
        queue<pair<int, int>>q ;
        int col = matrix[0].size() ;
        for(int i=0; i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(matrix[i][j] == 0)
                {
                    q.push({i, j}) ;
                }
            }
        }

        while(!q.empty())
        {
            pair<int, int> tmp = q.front() ;
            q.pop() ;
            int i = tmp.first ;
            int j = tmp.second ;
            if(i+1 < row)
            {
                if(res[i][j]+1 > res[i+1][j]){
                    res[i+1][j] = res[i][j]+1 ;
                    q.push({i+1,j}) ;
                }
            }
            if(j+1 < col)
            {
                if(res[i][j]+1 > res[i][j+1]){
                    res[i][j+1] = res[i][j]+1 ;
                    q.push({i,j+1}) ;
                }
            }
            if(i-1 >= 0)
            {
                if(res[i-1][j] < res[i][j]+1)
                {
                    res[i-1][j] = res[i][j]+1 ;
                    q.push({i-1,j}) ;
                }
            }
            if(j-1 >= 0)
            {
                if(res[i][j]+1 > res[i][j-1])
                {
                    res[i][j-1] = res[i][j]+1 ;
                    q.push({i,j-1}) ;
                }
            }
        }

        return res ;
    }
};
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

