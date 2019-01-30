#include <iostream>
#include<string>
#include<vector>
#include<iterator>
using namespace std;
class Solution{
public:
    int isContain(char ch ,vector<char>ss){
        for(int i=0;i<(int)ss.size()-1;i++){
            if(ss[i]==ch){
                return i;
            }
        }
        return -1;
    }
    void remove(int st,vector<char>&ss){
        
        vector<char>::iterator iter ;
        int i =0;
        for(iter=ss.begin();iter!=ss.end();){
            ss.erase(iter);   
            if(i==st)break;
            i++;
        }
    }

    int lengthOfLongestSubstring(string s) {
            int i=0,j;
            j=i+1;
            int ans=1;
            if(s==""){
                return 0;
            }
            if(s==" "){
                return 1;
            }
            int st;
            int l;
            vector<char>ss;
            ss.push_back(s[i]);
            int len = (int)s.length();
            while(j<len){
                
                ss.push_back(s[j]);
                l = (int)ss.size();
                if((st=isContain(s[j],ss))!=-1){
                   l = (int)ss.size()-1;
                    remove(st,ss);
                }
                ans = ans>l?ans:l;
                j++;
            }
            return ans;
    }
};
int main()

{
    Solution ss ;
    string a ;
    getline(cin,a);
    int n =ss.lengthOfLongestSubstring(a);
    cout<<n<<endl;
    return 0;
}

