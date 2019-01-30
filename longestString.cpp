#include <iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:

    int lengthOfLongestSubstring(string s) {
        int ans=0 ;
        int i=0,j=0;
        for(i = 0;i<(int)s.length();i++){
            for(j=i+1;j<(int)s.length();j++){
                if(isSame(s,i,j)){
                    ans = ans<(j-i)?(j-i):ans;
                }
            }
        }
        return ans;
    }
    bool isContain(char ch ,vector<char>ss){
        for(int i=0;i<(int)ss.size();i++){
            if(ss[i]==ch){
                return true;
            }
        }
        return false;
    }
    bool isSame(string s,int start,int end){
        vector<char>ss ;
        for(int i=start;i<end;i++){
            char ch = (s.data())[i];
            if(isContain(ch,ss)){
                return false;
            }
            ss.push_back(ch);
        }
        return true;
    }
};
int main()
{
    Solution ss ;
    string a ;
    cin>>a;
    int n =ss.lengthOfLongestSubstring(a);
    cout<<n<<endl;
    return 0;
}

