#include <iostream>
#include <vector>
#include <string.h>
using namespace std ;

class Solution {
public:
	void replaceSpace(char *str,int length) {
        string ls ;
        for(int i=0; i<length; i++) {
            if(str[i] != ' ') {
                ls.push_back(str[i]) ;
            }
            else {
                ls.push_back('%') ;
                ls.push_back('2') ;
                ls.push_back('0') ;
            }
        }
        strcpy(str, ls.c_str()) ;
	}
};

int main() {
    string ss ;
    Solution su ;
    getline(cin, ss) ;
    char* ch = new char[ss.size()];
    strcpy(ch, ss.data()) ;
    su.replaceSpace(ch, ss.size()) ;
    free(ch) ;
    return 0;
}

