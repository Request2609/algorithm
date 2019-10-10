#include <iostream>
#include <vector>
using namespace std ;
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int len = array.size() ;
        int sum= INT32_MIN, tmp = 0;
        for(int i=0; i<len; i++) {
            if(tmp > 0) {
                tmp += array[i] ;
            }
            else {
                tmp = array[i] ;
            }
            if(sum < tmp) {
                sum = tmp ;
            }
        }
        return sum ;
    }
};
int main() {
    
    Solution ss ;
    vector<int>ls ;
    while(1) {
        int a ;
        cin >> a ;
        if(a == 1000) {
            break ;
        }
        ls.push_back(a) ;
    }
    int s= ss.FindGreatestSumOfSubArray(ls) ;
    cout << s << endl ;
    return 0;
}

