#include <iostream>
#include<vector>
#include<stack>
#include<queue>
#include<memory>
using namespace std ;
class so ;
typedef shared_ptr<so>  sss;
class so
{
public :
    int x, y ;
    sss next;
public :
    so(int x, int y)
    {
        this->x = x ;
        this->y = y ;
    }
};

class Solution
{
public :
   
    int getShortest(int maze[][7],int board)
    {
        
        stack<sss>ls_tmp ;
        queue<sss>ls ;   
        sss tmp = make_shared<so>(1,1) ;
        ls.push(tmp) ;
        
        sss tt ;
        sss head = make_shared<so>(0,0) ;
        head->next = make_shared<so>(0,0) ;
        while(!ls.empty())
        {
            tt  = ls.front() ;
            //最先到达终点的直接退出
            cout << tt->x << "      " <<tt->y << endl ;
            if(tt->x == board && tt->y == board)
            {
                ls_tmp.push(tt) ;
                break ;
            }
                if(tt->x+1 <= board && maze[tt->x+1][tt->y] != 1)
                {
                    sss tt1 = make_shared<so>(tt->x+1, tt->y) ;
                    maze[tt->x+1][tt->y] = 1 ;
                    tt1->next = tt ;
                    ls.push(tt1) ;
                }
                if(tt->y+1 <= board&&maze[tt->x][tt->y+1] != 1)
                {
                    sss tt1 = make_shared<so>(tt->x, tt->y+1) ;
                    maze[tt->x][tt->y+1] = 1 ;
                    tt1->next = tt ;
                    ls.push(tt1) ;
                }
            
                if(tt->x-1 > 0 && maze[tt->x-1][tt->y] != 1)
                {
                    sss tt1 = make_shared<so>(tt->x-1, tt->y) ;
                    maze[tt->x-1][tt->y] = 1 ;
                    tt1->next = tt ;
                    ls.push(tt1) ;
                }


                if(tt->y-1 >0 &&maze[tt->x][tt->y-1] != 1)
                {
                    sss tt1 = make_shared<so>(tt->x, tt->y-1) ;
                    maze[tt->x][tt->y-1] = 1 ;
                    tt1->next = tt ;
                    ls.push(tt1) ;
                }
                ls_tmp.push(tt) ;
                ls.pop() ;
        }

        sss temp = ls_tmp.top() ;
        if(temp->x != board && temp->y != board)
        {
            return -1 ;
        }

         sss head1 = make_shared<so>(0,0) ;
         head1->next = make_shared<so>(0,0) ;
         sss t2 ;

         while(1)
         {
            if(temp->x==1&&temp->y==1)break ;
            cout << temp->x << "  ---  " << temp->y <<endl ;
            sss no = make_shared<so>(temp->x, temp->y) ;
            no->next = head1->next ;
            head1->next = no ;  
            temp=temp->next ;
         }
        
        sss no = make_shared<so>(temp->x, temp->y) ;
        no->next = head1->next ;
        head1->next = no ;

        while(temp->x&& temp->y)
        {
            cout << temp->x<<"    "<<temp->y <<endl ;
            temp = temp->next ;
        }
        return 1 ;
    }

} ;
int main()
{
    int maze[5][5] ={{0,1,0,0,0},{0,1,0,1,0},{0,0,0,0,0},{0,1,1,1,0},{0,0,0,1,0}} ;
    int maze_tmp[7][7] ;
    for(int i= 0; i< 7;i++)
    {
        for(int j =0;j<7;j++)
        {
            if(i==0||j==0||i==6||j==6)
            {
                maze_tmp[i][j] = -1 ;
            }
            else
            {
                maze_tmp[i][j] = maze[i-1][j-1] ;
            }
        }
    }
    Solution a ;
    a.getShortest(maze_tmp, 5) ;
    return 0;
}

