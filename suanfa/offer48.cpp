#include <iostream>
#include <unistd.h>

using namespace std ;

class Solution {
public:
    int StrToInt(string str) {
        char flag = '0' ;
        int index = 0 ;
        while(str[index] == ' ') {
            index++ ;
        }
        if(str[index] == '-') {
            flag = '-' ;
        }
        if(str[index] == '+') {
            flag = '+' ;
        }
        string num ;
        if(flag != '0') {
            index ++ ;
        }
        int len = str.length() ;
        while(index < len) {
            if(str[index] <= '9' && str[index] >= '0' ) {
                num+=str[index] ;
                index++ ;
            }
            else {
                return 0 ;
            }
        }
        long long int value ;
        //辨别是否溢出
        if(flag == '-') {
            string tmp = flag+num ;
            value = atoi(tmp.c_str()) ;
            if(value < INT32_MIN) {
                value = INT32_MIN ;
            }   
        }
        else {
            value = atoi(num.c_str()) ;
            if(value >= INT32_MAX) {
                value = INT32_MAX ;
            }
        }
        return value ;
    }
};

int main()
{
    string num ;
    getline(cin, num) ;
    Solution ss ;
    cout << ss.StrToInt(num) << endl ;
    return 0;
}

