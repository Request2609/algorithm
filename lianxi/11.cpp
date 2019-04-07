#include<iostream>
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
       
       for(int i=0; i < (int)prerequisites.size(); i++)
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
            cout << tmp <<endl;;
            ss.push_back(tmp) ;
            q.pop() ;
            for(size_t i=0; i< edge[tmp].size(); i++)
            {
                int t = edge[tmp][i] ;
                Ru[t] --;
                if(Ru[t]==0)
                {
                    q.push(t) ;
                }
            }
        }
        if(ss.size() == numCourses)
            return ss ;

        else 
        {
            ss.clear() ;
            return ss ;
        }
    }
};

class Solution1 {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> edge[2000];
        vector<int> In(numCourses,0);
        queue<int> Q;
        vector<int> ans;
        for(int i=0;i<prerequisites.size();i++)
        {
            edge[prerequisites[i].second].push_back(prerequisites[i].first);
            //根据起点统计入度的个数
            In[prerequisites[i].first]++;
        }

        for(int i=0;i<numCourses;i++)
            //出度的个数为0，表明是图的起点，将起点放进队列，开始拓扑排序
            if(In[i]==0)
                Q.push(i);
        while(!Q.empty())
        {
            int tmp=Q.front();
            Q.pop();
            ans.push_back(tmp);
            int t;
            for(int i=0;i<edge[tmp].size();i++)
            {
                t=edge[tmp][i];
                In[t]--;
                if(In[t]==0)
                    Q.push(t);
            }
        }
        if(ans.size()==numCourses)
            return ans;
        else
        {
            ans.clear();
            return ans;
        }
    }
};

int main()
{
    vector<pair<int, int>>ss ;
    ss.push_back(make_pair(1,0)) ;
    Solution s ;
    vector<int>a = s.findOrder(2,ss) ;
    for(size_t i=0;i< a.size();i++)
    {
        cout << a[i] <<endl ;
    }
}
