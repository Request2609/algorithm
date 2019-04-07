#include <iostream>
#include<vector>
using namespace std; 

class Solution {
public :
    int maxArea(vector<int>& height) {
                int maxs =  0 ;
                int  len = height.size() ;
                for(int i=0 ; i<len; i++)
                {       
                    dfs(height, i, len,maxs) ;
                }
                return maxs ;
            }
    void dfs(vector<int>&a,int s , int len, int& maxs)
    {
 
        for(int i = s+1;i<len;i++)
        {
            int num = min(a[s] , a[i])*abs(s-i) ;
            if(num > maxs)                                                                                  
            {
               maxs = num ;
            }
            dfs(a, i, len, maxs) ;
        }
    }
};
int main()
{
    int a ;
    vector<int>s ;
    while(1)
    {
        cin>>a ;
        if(a == -1)
            break ;
        s.push_back(a) ;
    }
    Solution ss ;
    cout << ss.maxArea(s) <<endl ;;
    return 0;
}

