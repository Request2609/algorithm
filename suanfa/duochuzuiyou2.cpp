#include <iostream>
#include <algorithm>
#include <vector>
using namespace std ;

double getRes(vector<int>&ls, int n) {
    int a[100] = {0};
    int len = ls.size() ;
    for(int i=0; i<len; i++) {
        int mins = INT32_MAX ;
        int k = 0 ;
        //获取当前服务站点的最短等待时间
        for(int j=0; j<n; j++) {
            if(mins > a[j]) {
                mins = a[j] ;
                k = j ;
            }
        }   
        a[k] += ls[i] ;
        ls[i] = a[k] ;
    }
    double sum = 0 ;
    for(int i=0; i<len; i++) {
        sum += ls[i] ;
    }
    return sum/len*1.0 ;
}
int main() {
    vector<int>ls ;
    int pnum, n ;
    cin >> pnum >> n ;
    while(pnum--) {
        int a ;
        cin >> a ;
        ls.push_back(a) ;
    }
    sort(ls.begin(), ls.end()) ;
    cout << getRes(ls, n) << endl ;
    return 0;
}

