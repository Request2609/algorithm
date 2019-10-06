#include <iostream>
#include <vector>
//排列组合
using namespace std ;

void swap(int& a, int& b) {
    int tmp = a ;
    a = move(b) ;
    b = move(tmp) ;
}

void pailie(vector<char>ls, int k) {
    int len = ls.size() ;

    if(k == len) {
        int l = ls.size() ;
        for(int i=0; i<l; i++) {
            cout << ls[i] ;
        }
        cout << endl ;
    }

    for(int i=k; i<len; i++) {
        if(i != k && ls[i] == ls[k]) {
            continue ;
        }
        swap(ls[k], ls[i]) ;
        pailie(ls, i+1) ;
        swap(ls[k], ls[i]) ;
    }
}

int main() {
    vector<char>ls ;
    while(1) {
        char a ;
        cin >> a ;
        if(a == '0') break ;
        ls.push_back(a) ;
    }
    pailie(ls, 0) ;
    return 0;
}

