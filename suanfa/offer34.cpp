#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;
//思想:初始数组为一个元素即0号元素为1，后面存数据就正常排序
//定义三个索引，index2, index3, index5
//里面的每一个丑数都是按照前面的丑数*2,*3,*5得到的
//我们假设数组中已经有若干个丑数，排好序后存在数组中，我们吧现在已经有的最大丑数记为M
//现在我们来生成下一个丑数，该丑数肯定是前面某一个丑数乘上2,3,5的结果
//我们首先考虑把已经有的每个丑数乘以2，在乘以2的时候，能得到若干个结果小于或者等于M的
//但只需要比M大的结果，因为我们想按照从小到大的顺序生成的，将得到的第一个乘以2后大于M的结果
//记为M2，同样，我们吧已经有的每一个丑数乘以3或者5，能得到第一个大于M的结果M3和M5，那么下一个丑数
//应该是M2,M3,M5中的最小的

class Solution {
public:
    int min(int a, int b, int c)
    {
        int temp = (a < b ? a : b);

        return (temp < c ? temp : c);
    }

    int GetUglyNumber_Solution(int N) {  
	
        int arr[10000] = {0};
        //初始化
        arr[0] = 1 ;
        int index2 = 0 ;
        int index3 = 0 ;
        int index5 = 0 ;
        int index = 1 ;
        while(index < N) {
            int val = min(arr[index2]*2, arr[index3]*3, 5*arr[index5]) ;
            if(val == arr[index2]*2) {
                ++index2 ;
            }
            if(val == arr[index3]*3) {
                ++index3 ;
            }
            if(val == arr[index5]*5) {
                ++index5 ;
            }
            arr[index++] = val ;
        }
        int result = arr[N-1] ;
        return result ;
    }
};

int main() {
    return 1 ;
}

