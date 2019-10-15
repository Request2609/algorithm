#include <iostream>
#include <vector>
using namespace std ;

//双指针的应用，和为S的连续两个数;
class Solution {
public:
    vector<vector<int>> FindContinuousSequence(int sum) {
        vector<vector<int>> ls ;
        int start =1, end =2;
        int s = 0 ;
        s+=start ;
        vector<int>tmp ;
        if(sum == 1 || sum ==2) {
            return ls ;
        }
        tmp.push_back(start) ;
        int flag =0  ;
        while(!tmp.empty()&&start < end) {
            cout << start <<  "      " << end << "       " << s << "       " << tmp.size()<< endl ;
            if(s == sum) {
                vector<int>ss = tmp ;
                print(tmp) ;
                if(ss.size() != 1)
                    ls.push_back(ss) ;
                s+=end ;
                tmp.push_back(end) ;
                cout << "jia--->" << end << endl ;
                flag =1  ;
            }
            else if(s < sum) {
                if(flag == 1) {
                    end++ ;
                    flag = 0 ;
                }
                s += end ;
                tmp.push_back(end) ;
                end++ ;
            }
            else {
                s -= start ;
                tmp.erase(tmp.begin()) ;
                start ++ ;
            }
        }
        if(ls.size() == 0) {
            return ls ;
        }
        return ls ;
    }
    void print(vector<int>ls) {
        int len =ls.size() ;
        for(int i=0; i<len; i++) {
            cout << ls[i] << " "  ;
        }
        cout << endl ;
    }
};

int main()
{
    Solution ss ;
    ss.FindContinuousSequence(15) ;
    return 0;
}

