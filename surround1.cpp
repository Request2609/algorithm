#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.size()==0)return;
        vector<vector<char>>ll ;
        
        int len=(int)board.size();
        int wid = (int)board[0].size();
        Init(len,wid,ll);
        for(int i= 0;i<wid;i++){
            Dfs(0,i,board,ll);
            Dfs(len-1,i,board,ll);
        }
        for(int i= 1;i<len-1;i++){
            Dfs(i,0,board,ll);
            Dfs(i,wid-1,board,ll);
        }

        board=ll;
    }
    
    void Dfs(int i,int j,vector<vector<char>>& board,vector<vector<char>>& ll){
        if(i<0||j<0||i>(int)board.size()-1||j>(int)board[0].size()-1||board[i][j]!='O')return ;
       
        board[i][j]='X';
        ll[i][j]='O';
        Dfs(i-1,j,board,ll);
        Dfs(i,j+1,board,ll);
        Dfs(i+1,j,board,ll);
        Dfs(i,j-1,board,ll);
    }
    
    void Init(int len,int wid,vector<vector<char>>& ll){
        
        for(int i = 0;i<len;i++){
            vector<char>s ;
            for(int j=0;j<wid;j++){
                char ch ='X';
                s.push_back(ch);
            }
            ll.push_back(s);
        }
    }
};
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

