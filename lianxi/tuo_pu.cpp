#include <iostream>
#include<vector>
#include<queue>
using namespace std ;

class Solution
{
public : 
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) 
    {
        //存储排序序列
        vector<int>ss ;
       // 保存边集
       vector<int> edge[2000] ;
       //记录当前节点入度的个数
       vector<int>Ru(numCourses, 0) ;
       //定义队列
       queue<int>q ; 
       for(int i=0; i < numCourses; i++)
       {
            edge[prerequisites[i].second].push_back(prerequisites[i].first) ;
        
            Ru[prerequisites[i].first]++ ;
       }

       //将入度为0的节点入队
       for(int i =0; i<numCourses; i++)
       {
            if(Ru[i]==0)
            {
                q.push(Ru[i]) ;
            }
       }
        //队列不空，开始拓扑
       while(!q.empty())
        {
            int tmp = q.front() ;
            ss.push_back(tmp) ;
            q.pop() ;
            for(size_t i=0; i< edge[tmp].size(); i++)
            {
                int t = edge[tmp][i] ;
                Ru[t] -- ;
                if(Ru[t]==0)
                {
                    q.push(t) ;
                }
            }
        }
        if(ss.size() == (size_t)numCourses)
            return ss ;

        else 
        {
            ss.clear() ;
            return ss ;
        }
    }
};

