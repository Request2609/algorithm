#include <iostream>
#include<string>
#include<vector>
using namespace std ;
/*91. 解码方法
题目描述
评论 (50)
题解
提交记录

一条包含字母 A-Z 的消息通过以下方式进行了编码：

'A' -> 1
'B' -> 2
...
'Z' -> 26

给定一个只包含数字的非空字符串，请计算解码方法的总数。

示例 1:

输入: "12"
输出: 2
解释: 它可以解码为 "AB"（1 2）或者 "L"（12）。

示例 2:

输入: "226"
输出: 3
解释: 它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 。

*/
class Solutions {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;
        int len = s.length();
        vector<int> dp(len, 0);
        dp[0] = s[0] == '0' ? 0 : 1;
        for (int i = 1; i < len; i++) {
            if (s[i] == '0') {
                if ('1' <= s[i-1] && s[i-1] <= '2') dp[i] = i >= 2 ? dp[i-2] : 1;
                else return 0;
            } else {
                if (s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6')) {
                    if(i<2)dp[i] = dp[i-1] + 1;
                    else dp[i] = dp[i-1]+dp[i-2];

                }
                else dp[i] = dp[i-1];
            }
        }
        return dp[len-1];
    }
};

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;
        int len = s.length();
        vector<int> dp(len, 0);
        dp[0] = s[0] == '0' ? 0 : 1;
        for (int i = 1; i < len; i++) {
            if (s[i] == '0') {
                
                if ('1' <= s[i-1] && s[i-1] <= '2') dp[i] = i >= 2 ? dp[i-2] : 1;
                else return 0;

            } else {
                if (s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6')) {
                    dp[i] = dp[i-1] + 1;
                    if (i >= 2) dp[i] += (dp[i-2] - 1);
                }
                else dp[i] = dp[i-1];
            }
        }
        return dp[len-1];
    }
};

/*class solution{

public :
    int numDecodings(string s) {
        if(s.empty()||s[0]=='0'){
            return 0 ;
        }
        unsigned int len = s.length() ;
        vector<int>dp(len,0); 
        dp[0] = s[0]=='0'? 0:1;
       
        for(unsigned int i=1;i<len;i++){
        
            if(s[i]=='0'){
                if('1'<=s[i-1]&&s[i-1]<=2) dp[i] = i >= 2?dp[i-2]:1 ;
                else return 0 ;
            }
            
            else{
                if(s[i-1]=='1'||(s[i-1]=='2'&&s[i]<='6')){
                
                    dp[i] = dp[i-1]+1 ;
                    if(i>=2){
                        dp[i]+=dp[i-2]-1 ;
                    }
                }
            
                else{
                    dp[i] = dp[i-1] ;
                }
            }
        }

        return dp[len-1] ;
        
    }
};*/
int main()
{
    string s ;
    cin>>s ;
    Solution ss ;
    cout<<ss.numDecodings(s) <<endl;
    
}

