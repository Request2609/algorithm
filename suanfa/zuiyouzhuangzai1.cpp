#include <iostream>
#include <vector>
using namespace std ;
//动态规划装载问题

int bestw ;

int a[1000][1000] ;
int main() {
    vector<int>ls ;
    int c1, c2 ;
    cin >> c1 >> c2 ;
    ls.push_back(0) ;
    int sum = 0 ;
    while(1) {
        int a ;
        cin >> a ;
        if(a == -1) {
            break ;
        }
        sum += a ;
        ls.push_back(a) ;
    }
    int maxs = 0 ;
    int len = ls.size() ;
    for(int i=1; i<len; i++) {
        //船的容量
        
    }
    return 0;
}
    
