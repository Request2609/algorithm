#include <iostream>
using namespace std ;

//整数因子分解问题
//大于1的整数n可以分解为n = x1*x2*x3...*x..
//求出该整数共有多少种分解方法

int fenjie(int n) {
    
    int count = 0 ;
    for(int i=n; i>1; i--) {
        //n能除尽i
        if(n%i == 0) {
            if(n != i) {
                count += fenjie(i) ;
            }
            else {
                count+=1 ;
            }
        }
    }       
    return count ;
}

int main() {

    int n ;
    cin >> n ;
    cout << fenjie(n) << endl ;
    return 0;
}

