#include <iostream>
using namespace std ;
/*
结题思路：假设n个节点存在二叉排序树的个数是G(n)，
1为根节点，2为根节点，...，n为根节点，当1为根节点时，
其左子树节点个数为0，右子树节点个数为n-1，同理当2为根节点时，
其左子树节点个数为1，右子树节点为n-2，
所以可得G(n) = G(0)*G(n-1)+G(1)*(n-2)+...+G(n-1)*G(0)
 *96. 不同的二叉搜索树
题目描述
评论 (45)
题解
提交记录

给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？

示例:

输入: 3
输出: 5
解释:
给定 n = 3, 一共有 5 种不同结构的二叉搜索树:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
 * */
class Solution {
public:
    int numTrees(int n) {
        
        int dp[10] ={0} ;
        for(int i=1;i<=n;i++){
            
            if(i==1||i==2){
                dp[i] = 1 ;
            }

            else{
                for(int j=1;j<=i;j++){

                    if(j==1){//只有右子树
                        dp[i] +=dp[i-j] ;
                    }

                    else if(j>1&&j<n){ //有左子树和右子树  
                        dp[i] += dp[i-j]*dp[j-1] ;
                    }

                    else{

                        dp[i]+= dp[j-1] ;
                    }
                }
            }
        }
        return dp[n] ;
    }
};
int main()
{

    return 0;
}

