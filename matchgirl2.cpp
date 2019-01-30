#include <iostream>
#include <vector>
#include <algorithm>
#include<numeric>
using namespace std;
class Solution {
public:
    bool makesquare(vector<int>& nums) {
        
        
        if(nums.size() < 4)
            return false;
        
        int sum =0;
        for(int i =0;i<(int)nums.size();++i)
            sum += nums[i];
        
        if(sum%4 !=0)
            return false;
        //按照长度从大到小的顺序排列火柴
        sort(nums.rbegin(),nums.rend());
        
        //设置四条边的集合
        int line[4] ={0};
        
        return IsOk(0,nums,sum/4,line);
    }
    
    bool IsOk(int i,vector<int>& nums, int target,int line[])
    {

        if(i ==(int)nums.size())
            return line[0] == target && line[1] == target && line[2] == target && line[3] == target;
        
        
        for(int j =0;j<4;++j)
        {
            //要是当前边与火柴长度的和比期望长度大,就将当前火柴与下一条边匹配
            if(line[j] + nums[i] > target)
                continue;
            //拼凑期望边长
            line[j] += nums[i];
            //递归调用,和下一个火柴匹配
            if(IsOk(i + 1,nums,target,line))
                return true;
           //说明该边长的所有火柴组合不恰当 ,应该拆开重新组合
            line[j] -= nums[i];
        }
        return false;
    }
};
int main()
{
    Solution ss ;
    vector<int>s ;
    int a ;
    while(cin>>a){
        if(a==-1)break ;
        s.push_back(a);
    }
    cout<<ss.makesquare(s)<<endl;
    
    return 0;
}

