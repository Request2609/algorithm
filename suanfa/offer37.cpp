#include <iostream>
#include <vector>
#include <map>
using namespace std ;

class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        map<int , int> ls ;
        int len = data.size() ;
        for(int i=0; i<len; i++) {
            if(ls.find(data[i]) == ls.end()) {
                ls[data[i]] = 1 ;
            }
            else {
                ls[data[i]] ++ ;
            }
        }
        for(auto res=ls.begin(); res != ls.end(); res++) {
            if(res->first == k) {
                return res->second ;
            }
        }
        return 0 ;
    }
};
int main()
{
    vector<int>ls ;
    for(int i=0;  i<5; i++) {
        int a ;
        cin >> a ;
        ls.push_back(a) ;
    }
    Solution ss ;
    cout << ss.GetNumberOfK(ls, 3) << endl  ;
    return 0;
}

