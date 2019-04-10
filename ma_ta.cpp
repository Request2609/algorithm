#include <iostream>
#include<stack>
#include<strings.h>
#include<string.h>
#include<vector>
using namespace std ;
//定义马跑的方向

//栈中的元素
typedef struct node
{   
    
    int x, y ;

}node_t;

int a[8][2] = {{-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}} ;

//棋盘
int maze[8][8]= {{0}} ;
int qi_pan[8][8] = {{0}} ;
stack<node_t>s ;

void init_maze() ;
void get_can_go_num(int i, int j) ;
void print() ;
void go_maze(int i, int j, int counts) ;
void get_next_min(node_t& tmp) ;

int main()
{
    init_maze() ;
    int i=0, j= 0;
    int counts = 1 ;
    go_maze(i, j, counts) ;
    print() ;
    return 0;
}

//走迷宫
void go_maze(int i, int j, int& counts)
{   
    if(i<0||j<0||i>=8||j>=8)
    {
        return ;
    }
    
    node_t node ;
    node.x = i;
    node.y = j ;
    s.push(node) ;
    while(!s.empty()&&counts != 64)
    {
        qi_pan[i][j] = counts ;
        node_t tmp = s.top();
        get_next_min(tmp) ;  
        if(tmp.x == -1)
        {
            
            s.pop();
        }

        else
        {
            s.push(tmp) ;
            counts++ ;
        }
    }
}

//获取下一个联通节点个数最少位置
void get_next_min(node_t& tmp)
{

    //当前节点的相邻接点个数
    int cur_x = tmp.x,cur_y = tmp.y ;

    int n = maze[tmp.x][tmp.y] ;
    if(n == 0)
    {
        return ;    
    }

    int i = 0;
    int mins = 0 ;
    node_t next_best ;
    memset(&next_best, 0, sizeof(next_best)) ;

    int flag = 0 ;

    while(n)
    {
        int row = a[i][0]+cur_x ;
        int col = a[i][1]+cur_y ;
        if((row>=8&&row<0&&col<0&&col>=8)||(a[row][col]!=0))
        {
            i++ ;
            continue ;
        }
        
        
        if(maze[row][col] < mins)
        {
            flag = 1 ;
            next_best.x = row ;
            next_best.y = col ;
            mins = maze[row][col] ;
        }

        n-- ;
    }
    
    if(flag == 0)
    {
        tmp.x = -1 ;
        tmp.y = -1 ;
        return ;
    }

    maze[cur_x][cur_y]-- ;
    tmp.x = next_best.x ;
    tmp.y = next_best.y ;
    maze[tmp.x][tmp.y]-- ;
}

void print()
{
    int row = 8;
    int col = 8 ;
    for(int i=0; i< row; i++)
    {
        for(int j= 0; j<col ;j++)
        {
            cout << maze[i][j]<<"  " ;
        }
        cout << endl ;
    }
}

//初始化棋盘
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


//统计期盼每个节点相邻的合法节点个数
void get_can_go_num(int row, int col)
{
    for(int i=0; i<8; i++)
    {
        int rows = row+a[i][0];
        int cols = col+a[i][1] ;
        if(rows>=0&&rows<8&&cols>=0&&cols<8)
        {
            maze[row][col]++ ;
        }
    }
}
