#include <iostream>
#include <vector>
#include <map>
using namespace std ;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.size() == 1) {
            return numbers[0] ;
        }
        map<int, int>ls ;
        int len = numbers.size() ;
        for(int i=0; i<len; i++) {
            if(ls.find(numbers[i]) != ls.end()) {
                ls[numbers[i]]++ ;
                if(ls[numbers[i]]>len/2) {
                        return numbers[i] ;
                }
            }
            else {
                ls[numbers[i]] = 1 ;
            }
        }
        return 0 ;
    }
};
int main() {
    vector<int>ls ;
    while(1) {
        int a ; 
        cin >> a ;
        if(a == -1){
            break ;
        }
        ls.push_back(a) ;
    }
    Solution ss ;
    cout << ss.MoreThanHalfNum_Solution(ls) << endl ;
    return 0;
}

