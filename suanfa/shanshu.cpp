#include <iostream>
#include <string.h>
using namespace std ;
//删数问题
int main() {
    string a ;
    int n ;
    cin >> a ;
    cin >> n ;
    int len = a.size() ;

    for(int i=0; i<n; i++) {
        for(int i=0; i<len-1; i++) {
            if(a[i] > a[i+1]) {
                a[i] = a[i+1] ;
            }
        }   
        len -- ;
    }
    for(int i=0; i<len; i++) {
        cout << a[i];
    }
    return 0;
}

