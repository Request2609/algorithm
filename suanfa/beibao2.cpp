#include <iostream>
using namespace std ;

int getRes(int n, int ww, int v[], int w[]) {

    int ret  = 0 ;
    int res[100] = {0} ;
    for(int i=1; i<=n; i++) {
        for(int j=ww; j>=w[i]; j--) {
            //将剩余质量为j时的最大价值和装入第i个物品的时候的价值进行对比
            res[j] = max(res[j], res[j-w[i]]+v[i]) ;
            ret = res[j] ;
        }
    }

    return ret ;
}

int main() {
    int w[] = {0, 5, 4, 7, 2, 6} ;
    int v[] = {0, 12, 3, 10, 3 ,6} ;
    int maxw ;
    cin >> maxw ;
    cout <<  getRes(5, maxw, w, v) << endl ;
    return 0;
}


