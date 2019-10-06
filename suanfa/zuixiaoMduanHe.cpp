#include <iostream>
#include <vector>
using namespace std ;

int MAX = 100000 ;
int a[100] ;
int f[100][100] ;

int getMax(int x, int y) {
    return x<y?y:x ;
}
//dp
//最小m段和和最大k乘积是一种方法进行解决
int getRes(int len, int n) {//长度为len的数组分成n段的最大最小值
    f[0][1] = 0 ;
    int temp = MAX;
    int mins ;
    //前i-1段加当前
    for(int i=1; i<len; i++) {
        f[i][1] = f[i-1][1] + a[i] ;
    }
    //主要思想就是将所有段数最优分法都计算出来
    //控制分的长度
    for(int i=2; i<=len; i++) {
        //里面两层计算前i个元素分成n端的最大最小值
        //控制分成多少段
        for(int j=2; j<=n; j++) {   
            //控制遍历到第几个数,计算前i个数分成j段的最大最小值
            temp = MAX ;
            for(int k=1; k<i; k++) {
                //使用前i个数的和减去前k个数的和将前k个数的序列分成j-1段时的最大值进行比较
                //获取最大的值//将前ｋ个元素分成j-1段的最大最小值表示为f[k][j-1]
                //其中里面组合起来就是将前i个元素分成j段
                mins = getMax(f[i][1]-f[k][1], f[k][j-1]) ;
                //要是当前最大值小于之前的最大值,记录下来
                if(mins < temp) {
                    //记录最大值
                    temp = mins ;
                }
            }    
            f[i][j] = temp ;
        }
    }
    return f[len][n] ;
} 

//将前n个数分成n段获取最大最小值
int main() {

    int i=0; 
    while(i++){
        cin >> a[i] ;
        if(a[i] == -1) {
            break ;
        }
    }
    int n ;
    cin>> n ;
    getRes(i, n) ;
    return 0;
}

