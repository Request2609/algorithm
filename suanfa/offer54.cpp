#include <iostream>
#include <string.h>
using namespace std ;

class Solution
{
public:
    bool match(const char *s, const char *p) {
        if(*p == '\0') {
            return !(*s) ;//串s匹配到末尾，成功！
        }
        int len = strlen(s) ;
        int plen = strlen(p) ;
        //正则串只有一个长度并且匹配*
        if(plen == 1 || *(p+1) != '*') {
            return len&&(p[0] == '.' || *s==*p)&&match(s+1, p+1) ;
        }
        else {
            //匹配一个字符
            while(*s != '\0' &&(*p == '.' || *s == *p)) {
                if(match(s++, p+2)) {
                    return true ;
                }
            } 
        }
        //要是*(p+1)是*的话，就将p指针向后移动两个长度
        //a.a     ab*ac*a
        return match(s, p+2) ;
    }
} ;

int main()
{
    return 0;
}

