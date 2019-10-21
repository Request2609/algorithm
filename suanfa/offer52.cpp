#include <iostream>
#include <vector>

using namespace std ;

class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int len = A.size() ;
        vector<int>ss ;
        int h = 1 ; 
        int flag = 0 ;
        for(int i=0; i<len; i++) {
            if(A[i] == 0) {
                //统计0出现的次数
                flag ++ ;
                continue ;
            }
            h *= A[i] ;
        }

        for(int i=0; i<len; i++) {
            int tt = 0 ;
            if(A[i] == 0) {
                if(flag == 1) {
                    tt = h ;
                }
                else {
                    tt = 0 ;
                }
                ss.push_back(tt) ;
                continue ;
            }
            if(flag == 0) {
                tt = h/A[i];
            }
            else {
                tt = 0 ;
            }
            ss.push_back(tt) ;
        }
        return ss ;
    }
};
int main() {
    vector<int>ls ;
    while(1) {
        int a ;
        cin >> a ;
        if(a == -1) break ;
        ls.push_back(a) ;
    }
    Solution ss ;
    vector<int>s = ss.multiply(ls) ;
    int len = s.size() ;
    for(int i=0; i<len; i++) {
        cout << s[i] << "  " ;
    }
    cout << endl ;
    return 0;
}

