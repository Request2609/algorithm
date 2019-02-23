#include <iostream>
/**
 *
 *给定一个由 '1'（陆地）和 '0'（水）组成的的二维网格，计算岛屿的数量。一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围。

示例 1:

输入:
11110
11010
11000
00000

输出: 1

示例 2:

输入:
11000
11000
00100
00011

 *
 * */
#include<vector>

using namespace std;
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int res = 0 ;
        for(int i =0 ;i < (int)grid.size();i++){
            for(int j= 0;j<(int)grid[i].size();j++){
                if(grid[i][j]=='0'){
                    continue;
                }
                res++;
                Dfs(i,j,grid);
            }   
        }
        return res;
    }

    void Dfs(int i,int j,vector<vector<char>>& grid){
        if(i<0||j<0||i>(int)grid.size()-1||j>(int)grid[i].size()-1||grid[i][j]!='1'){
            return ;
        }
        
        grid[i][j]='0';
        Dfs(i-1,j,grid);
        Dfs(i,j+1,grid);
        Dfs(i+1,j,grid);
        Dfs(i,j-1,grid);
    }
};
int main()
{
    Solution ss;
    vector<vector<char>>a ;
    vector<vector<char>>k ;
    vector<char>s;
    while(1){
        char l ;
        while(cin>>l){
            if(l=='3')break;
            s.push_back(l);
        }
        if(s[0]!='3'){
             break;   
        }
        a.push_back(s);
    }
    k=a;
    cout<<ss.numIslands(a)<<endl;
    return 0;
}

