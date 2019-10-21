#include <iostream>
#include <vector>
using namespace std ;

class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    { 
        if(n == 0) return -1 ;
        vector<int>ls ;
        for(int i=0; i<n; i++) {
            ls.push_back(i) ;
        }
        vector<int>::iterator iter ;
        int count = 0 ;
        int flag = 0 ;
        for(auto res=ls.begin(); ; ) {
            if(ls.size() == 1) {
                return ls[0] ;
            }
            cout << count <<"     " << m<< endl ;
            if(count == m) {
                count= 0 ;
                ls.erase(res) ;
                res = iter ;
            }
            if(res != ls.begin() || res!= ls.end())  {
                if(flag == 0) {
                    res ++ ;
                    iter = res + 1 ;
                }
                else {
                    res-- ;
                    iter = res-1 ;
                }
            }
            if(res == ls.end() && flag == 0) {
                flag = 1 ;
                res-- ;
                iter = res-1 ;
            }
            else if(res == ls.begin() && flag == 1) {
                flag = 0;
                res++ ;
                iter = res+1 ;
            }
            count ++ ;
        }
        return -1 ;
    }
};
int main()
{
    Solution ss ;
    cout << ss.LastRemaining_Solution(5, 8) << endl ;
    return 0;
}

