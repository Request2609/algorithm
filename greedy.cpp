#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
         
        size_t len = gas.size();
        int st=0;
        size_t i;
        for(i=0;i<len;i++)
        {   
            int sum=0;
            int st = 0 ;
            size_t pos;
            sum=gas[i];
            pos = i+1;
            if(pos==len){
                pos=0;
            }
            while(1){
                st++;
                int po ;
                
                if(pos==len-1){
                    sum+=gas[0]-cost[pos];
                    po = pos ;
                }
                
                else{
                    sum +=gas[pos+1]-cost[pos];
                    po = pos+1;
                }
                
                if(sum<0||sum<cost[po]){
                    break;
                }

                else{
                    if(pos==len-1){
                        pos=0;          
                    }
                    else pos = pos+1;
                   }
            }
            if(st==len)break;
        }
        cout<<st<<endl;
        return  st==len?i:-1;
    }
};
int main()
{
    int a ;
    vector<int>s ;
    vector<int>ss;
    while(cin>>a){
        if(a==-1)break;
        s.push_back(a);
    }
    while(cin>>a){
        if(a==-1)break;
        ss.push_back(a);
    }
    Solution cc;
    cout<<cc.canCompleteCircuit(s,ss);
    return 0;
}

