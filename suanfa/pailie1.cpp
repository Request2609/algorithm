#include <iostream>
#include <string>
#include <vector>
using namespace std ;


void pailie(vector<char>&ls, int k) {
    int size = ls.size() ;
    if(k == size-1) {
        for(int i=0; i<size; i++) {
            cout << ls[i] << "" ;
        }
        cout << endl ;
    }
    for(int i=k; i<size; i++) {
        swap(ls[i], ls[k]) ;
        pailie(ls, k+1) ;
        swap(ls[i], ls[k]) ;
    }
}

int main() {
    vector<char> aa ;
    while(1) {
        char a ;
        cin >> a ;
        if(a == '0') {
            break ;
        }
        aa.push_back(a) ;
    }    
    int i = 0 ;
    pailie(aa, i) ;
    return 0;
}

