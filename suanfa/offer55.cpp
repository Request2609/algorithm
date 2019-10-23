#include <iostream>
#include <string.h>
#include <string>
using namespace std ;

class Solution {
public:
    bool isNumeric(const char* str) {
        int len = strlen(str);
        if(len == 0) {
            return false ;
        }
        int d = 0 ;
        int flag = 0 ;
        int index = 0 ;
        if(str[index] == '+' || str[index] == '-') {
            flag = 1 ;
        }
        if(flag == 1) {
            index++ ;
        }
        int ed = 0 ;
        int fu = 0 ;
        int count = 0 ;
        int dnum = 0 ;
        int edNum = 0 ;
        //第一个要是数字字符
        if(isNum(str[index])) {
            index ++ ;
            while(index<len) {
                if(isNum(str[index])) {
                    if(str[index] == 'E' || str[index] == 'e') {
                        ed = index ;
                        edNum ++ ;
                    }
                    if(str[index] == '.') {
                        d = index ;
                        dnum ++ ;
                    }
                }
                else if(str[index] == '+' || str[index] == '-') {
                    fu = index ;
                    count++ ;
                }
                else {
                    return false ;
                }
                index++ ;
            }
        }
        else {
            return false ;
        }
        if(fu !=0 && ed == 0) {
            return false ;
        }
        if((fu!=0&&fu < d) || count>1 || dnum > 1 || edNum > 1 || (ed > fu&&fu!=0) || str[len-1] == 'e' || str[len-1] == 'E') {
            return false ;
        }
        return true ;
    }
    bool isNum(const char s) {
        return (s== '.' ||(s >= '0' && s <= '9')||s == 'e' || s == 'E') ;
    }

};
int main() {
    Solution ss ;
    string s ;
    cin >> s ;
    cout << ss.isNumeric(s.data()) << endl ;
    return 0;
}

