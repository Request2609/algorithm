#include <iostream>
#include <vector>
using namespace std ;

//最大子段和
int getMax(vector<int>ls) {
    int sum = 0, b = 0 ;
    for(int i=0; i<(int)ls.size(); i++) {
        //前面的值之和大于０,继续累加后面的值
        if(b > 0) {
            b+=ls[i] ;
        }
        //负值已经大于前面的正值
        else {
            b = ls[i] ;
        }
        //要是当前的和大于sum(当前最大段的和),重新置sum
        if(b>sum) {
            sum = b ;
        }
    }
    return sum ;
}

int main() {
    vector<int>ls ;
    while(1) {
        int n ;
        cin >> n ;
        if(n == -1) {
            break ;
        }
        ls.push_back(n) ;   
    }
    cout << getMax(ls)<< endl  ;
    return 0;
}

