#include <iostream>
#include <vector>
#include <algorithm>
#include<numeric>
using namespace std;

/*
 *还记得童话《卖火柴的小女孩》吗？现在，你知道小女孩有多少根火柴，请找出一种能使用所有火柴拼成一个正方形的方法。不能折断火柴，可以把火柴连接起来，并且每根火柴都要用到。

输入为小女孩拥有火柴的数目，每根火柴用其长度表示。输出即为是否能用所有的火柴拼成正方形。

示例 1:

输入: [1,1,2,2,2]
输出: true

解释: 能拼成一个边长为2的正方形，每边两根火柴。

示例 2:

输入: [3,3,3,3,4]
输出: false

解释: 不能用所有火柴拼成一个正方形。

注意:

    给定的火柴长度和在 0 到 10^9之间。
    火柴数组的长度不超过15。


 **/
/*
建立一个长度为4的数组sums来保存每个边的长度和，我们希望每条边都等于target=sum/4。
然后我们遍历sums中的每条边，我们判断数组中的当前数字是否大于target，那么我们跳过，
如果没有，我们就加上这个数字，然后对数组中下一个位置调用递归，如果返回为真，我们返回true，
否则我们再从sums中对应位置将这个数字减去继续循环.
如果第一根火柴在第一条边上都放不进去的话，后面也都不用试了，因为每条边长都一样，一个放不进去的话其他也放不进去。
其实不只是第一根火柴，由于较长的火柴较不容易放入边中，所以如果我们先把较长的火柴放完再放较短的火柴，能帮助减少很多分叉的情况。
所以这里一个优化的方法就是先将火柴排序，将长的放在前面。
*/
class Solution {
public:

    bool makesquare(vector<int>& nums) {

        if(nums.empty()||nums.size()<4) return false;
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum % 4 != 0) return false;
        vector<int> sums(4,0);  //长度为4的数组sums来保存每个边的长度和
        //有大到小排序
        sort(nums.rbegin(),nums.rend());
        return helper(nums,sums,0,sum/4);
    }
    bool helper(vector<int>& nums,vector<int>& sums,int pos,int target){
      
        if(pos >= (int)nums.size()){
            return sums[0] == target && sums[1] == target && sums[2] == target && sums[3] == target;
        }

        //对于当前这个火柴，尝试拼入上下左右四个边
        for(int i=0;i<4;++i){
            if(sums[i]+nums[pos] > target) continue;

            sums[i] += nums[pos]; //把当前火柴从i个边中拿出来，好尝试下一条边
            if(helper(nums,sums,pos+1,target)) {
                    
                    return true; 
            } //如果这个火柴被成功使用，就开始尝试拼下一根火柴
            sums[i] -= nums[pos];  //用当前火柴拼第i个边
        }
        return false;
    }
};

int main(){
    
    Solution ss ;
    vector<int>s ;
    int a ;
    while(cin>>a){
        if(a==-1)break ;
        s.push_back(a);
    }
    cout<<ss.makesquare(s)<<endl;
    
}
