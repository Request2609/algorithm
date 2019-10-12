#include <iostream>
#include <vector>
#include <map>
using namespace std ;
//找第一个只出现一次的字符

class node {
public :
    int index = 0 ;
    int count = 0;
    char c ;
} ;


class Solution {
public:
int FirstNotRepeatingChar(string str) {
    map<char, node> ls ;
        int len = str.size() ;
        for(int i=0; i<len; i++) {
            if(ls.find(str[i]) != ls.end()) {
                ls[str[i]].count++ ;       
                continue ;
            }
            node nn ;
            nn.c = str[i] ;
            nn.count ++ ;
            nn.index = i ;
            ls[nn.c] = nn ;
        }   
        int min = len+1 ;
        char index = -1;
        char cc ;
        for(auto t = ls.begin(); t != ls.end(); t++) {
            if(t->second.count == 1) {
                int tmp = t->second.index ;
                if(tmp < min) {
                    cc = t->second.c ;
                    min = tmp ;
                    index = t->second.index  ;  
                }
            }
        }
        cout << cc << endl ;
        return index ;
    }
};
int main() {
    Solution ss ;
    cout << ss.FirstNotRepeatingChar("hheoello04") << endl ;
    return 0;
}

