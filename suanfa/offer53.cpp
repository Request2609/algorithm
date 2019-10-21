#include <iostream>
#include <vector>
#include <string.h>
using namespace std ;

class Solution {
public:
    bool match(char* str, char* pattern) {
        int len1 = strlen(str) ;
        int len2 = strlen(pattern) ;
        int index1 = 0 ;
        int index2 = 0 ;
        while(index1 < len1 && index2 < len2) {
            if(str[index1] != pattern[index2]) {
                if(str[index1] != '.' || str[index1] != '*') {
                    if(pattern[index2] != '.') {
                        return false ;
                    }
                    else if(pattern[index2] == '*') {
                        if(index1-1 > 0) {
                            if(str[index1-1] != str[index1]) {
                                return false ;
                            } 
                        } 
                    }
                    else if((index2+1<len2) && pattern[index2+1] == '*') {
                        index2+=2 ;
                    }
                }
                if(pattern[index2] != '.' || pattern[index2] != '*') {
                        
                }
                else {
                    
                }
            }
            index1++ ;
            index2++ ;
        }
        return true ;
    }
};
int main() {

    return 0;
}

