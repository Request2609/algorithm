#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std ;

struct Compare {
    bool operator()(const string& a, const string& b) {
        string ab = a+b ;
        string ba = b+a ;
        return ab>ba?0:1 ;
    }
} ;
class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        vector<string>number ;
        int len = numbers.size() ;
        for(int i=0; i<len; i++) {
            number.push_back(to_string(numbers[i])) ;
        }
        sort(number.begin(), number.end(), Compare()) ;
        string aa ;
        len = number.size() ;
        for(int i=0; i<len; i++) {
            aa+=number[i] ;
        }
        return aa ;
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
    cout << ss.PrintMinNumber(ls) << endl ;
    return 0;
}

