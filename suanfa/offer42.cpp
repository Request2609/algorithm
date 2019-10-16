#include <iostream>
#include <string>
using namespace std ;

class Solution {
public :
    string LeftRotateString(string str, int n) {
        string strs ="";
        if(str.size() == 0) {
            return strs ;
        }
        Reverse(str, 0, n-1) ;
        Reverse(str, n, str.size()-1) ;
        Reverse(str, 0, str.size()-1) ;
        return str ;
    }   
    void Reverse(string&str, int left, int right) {
        while(left < right) {
            swap(str[left], str[right]) ;
            left++ ;
            right -- ;
        }
    }
} ;
int main()
{
    return 0;
}

