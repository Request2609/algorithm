#include <iostream>
using namespace std  ;

//背包问题(01)
//获取结果
int getRes(int w[], int v[], int len, int ww) {
    int res[100][100] = {{0}} ;
    int ret ;
    for(int i=1; i<=len; i++) {
        for(int j=0; j<=ww; j++) {
            //当前的物品质量不大于剩余的质量
            //取放上一个物品所得的最大质量
            if(j < w[i]) {
                res[i][j] = res[i-1][j]  ;     
            }
            else {
                //将放物品和没放物品的时候所记录价值进行比较得到最大值
                res[i][j] = max(res[i-1][j], res[i-1][j-w[i]]+v[i]) ;
                //这就是最大价值
                ret = res[i][j] ;
            }
        }
    }   
    return ret ;
}

int main() {
    int w[] = {0, 5, 4, 7, 2, 6} ;
    int v[] = {0, 12, 3, 10, 3 ,6} ;
    int maxw ;
    cin >> maxw ;
   cout <<  getRes(w, v, 5, maxw)  ;
    return 0;
}

