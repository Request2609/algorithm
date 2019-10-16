#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std ;

class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
if(numbers.size() == 0) {
	return false ;
}
        int flag = 0 ;
        int count = 0 ;
        int index = 0 ;
        int sum = 0;
        sort(numbers.begin(), numbers.end()) ;
        for(auto i= 0; i != numbers.size(); i++) {
            if(numbers[i] == 0) {
                count ++ ;
                flag = 1 ;
                continue ;
            }
            else {
                if(flag == 1) {
                    flag = -1 ;
                    continue ;
                }
                int ret = numbers[i]-numbers[i-1] ; 
                if(ret == 0) {
                    return false ;
                }
                if(ret != 1) {
                   sum += ret-1 ; 
                }
            }
        }
        cout << sum << "   " << count << endl ;
        return count >= sum ?1:0 ;
    }
    void print(vector<int>ls) {
        int len =ls.size() ;
        for(int i=0; i<len; i++) {
            cout << ls[i] << "   ";
        }
        cout << endl ;
    }
};

int main() {
    vector<int>ls ;
    while (1){
        int a ;
        cin >> a ;
        if(a == -1) {
            break ;
        }
        ls.push_back(a) ;
    }
    Solution ss ;
    cout << ss.IsContinuous(ls) << endl ;
    return 0;
}

