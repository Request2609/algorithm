#include <iostream>
#include <map>
#include <vector>
using namespace std ;

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        map<int, int>ls ;
        int len = data.size();
        for(int i=0; i<len; i++){
            if(ls.find(data[i]) != ls.end()) {
                ls[data[i]]++ ;
            }
            else {
                ls[data[i]] = 1 ;
            }
        }

        for(auto res = ls.begin(); res!=ls.end(); res++) {
            cout << res->second << "     " << res->first << endl;
        }
        cout << "开始查找～！" << endl;
        int flag = 1;
        for(auto res =ls.begin(); res != ls.end(); res++) {
            cout << res->second << "     " << res->first << endl ;
            if(res->second == 1) {
                if(flag == 1) {
                    *num1 = res->first ;
                }
                if(flag == 2) {
                    *num2 = res->first ;
                    break ;
                }
                flag ++ ;
            }
        }
    }
};
int main() {
    vector<int>ls ;
    while(1) {
        int a ;
        cin >> a ;
        if(a == -1) {
            break ;
        }
        ls.push_back(a) ;                                                                                                                                                                                                                                                       
    }
    Solution sl ;
    int num = 0 ;
    int num1 = 0 ;
    sl.FindNumsAppearOnce(ls, &num, &num1) ;
    if(num != 0) {
        cout << num << endl ;
    }
    if(num1 != 0) {
        cout << num1 << endl ;
    }
}

