#include <iostream>
#include<vector>
using namespace std ;
//定义马跑的方向

int a[8][2] = {{-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}} ;

//棋盘
int maze[8][8]= {{0}} ;
void init_maze() ;
void get_can_go_num(int i, int j) ;
int main()
{
    init_maze() ;
    return 0;
}

void init_maze()
{   
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            get_can_go_num(i,j) ;
        }
    }
}

void get_can_go_num(int row, int col)
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            if(row-a[i][j]l)
        }
    }
}
