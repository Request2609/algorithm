#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std ;

vector<int>ls ;
class Solution {
public:

    void swap(int& c1, int& c2) {
        int a ;
        a = move(c1) ;
        c1 = move(c2) ;
        c2 = move(a) ;
    }

    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int>ls ;
        int len = input.size() ;
        for(int i=0; i<k; i++) {
            ls.push_back(input[i]) ;
        }
        if(len == k) {
            return ls ;
        }
        if(len < k) {
            ls.clear() ;
            return ls ;
        }
        //从小到大排个序
        sort(ls.begin(), ls.end()) ;
        int t = k ;
        int s = 0;
        while(1) {
            if(t >= len) {
                break ;
            }
            int flag =0  ;
            for(int i=s; i<k; i++) {
                if(ls[i] > input[t]) {
                    s = i+1 ;
                    flag = 1 ;
                    swap(ls[i], input[t]) ;
                    break ;
                }
            }
            if(flag == 1) {
                continue ;
            }
            s = 0 ;
            t++ ;
        }
        return ls ;
    }
};

int main() {
    int n ;
    vector<int>ls ;
    while(1) {
        int a ;
        cin >> a ;
        if(a == -1) break ;
        ls.push_back(a) ;
    }
    cin >> n ;
    Solution ss ;
    ss.GetLeastNumbers_Solution(ls, n) ;
    return 0;
}

