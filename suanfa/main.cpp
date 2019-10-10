#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std ;

int main()
{
    vector<string>ls ;
    while(1) {
        string a ;
        cin >> a ;
        if(a == "-1") {
            break ;
        }
        ls.push_back(a) ;
    }
    sort(ls.begin(), ls.end()) ;

    int len = ls.size() ;
    for(int i=0; i<len; i++) {
        cout << ls[i] << endl ;
    }
    return 0;
}

