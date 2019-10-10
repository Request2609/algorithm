#include <iostream>
#include <cmath>
using namespace std ;

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n) {
        return countOne(n) ;   
    }   
    int countOne(int n) {
        long count = 0 ;
        if(n==0) {
            count = 0 ;
        }
        //小于10就count+1
        else if(n>1&&n<10) {
            count = 1 ;
        }
        else {
            long highest = n ;
            int bit = 0 ;
            while(highest>=10) {
                highest = highest/10 ;
                bit++ ;
            }
            //循环结束的时候，bit表示n的位数,hightest表示最高位数
            int weight = pow(10, bit) ;
            //分治算法
            if(highest == 1) {
                count = highest*countOne(weight-1)+countOne(n-weight)+(n-weight+1) ;
            }
            else {
                count = highest*countOne(weight-1)+countOne(n-highest*weight)+weight ;
            }
        }
        return count ;
    }
};
int main() {
    return 0;
}

