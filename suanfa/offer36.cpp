#include <iostream>
#include <vector>
using namespace std ;

class Solution {
public:
    void swap(int& a, int& b) {
        int aa ;
        aa = move(a) ;
        a = move(b) ;   
        b = move(aa) ;
    }
    //暴力解法
    int InversePairs(vector<int> data) {
        int count = 0 ; 
        int len = data.size() ;
        int k = 0 ;
        while(k<len) {
            for(int j=k+1; j<len; j++) {
                if(data[k] > data[j]) {
                    cout << data[k] <<"  "  << data[j] << endl;
                    count ++ ;
                }
            }    
            k++ ;
        }   
        for(int i=0; i<len; i++) {
            cout << data[i] << "  " ;
        }   
        cout << endl ;
        return count ;
    }   
    int Merge(vector<int>&elem, int start, int& mid, int& end, vector<int>&temp) {
        int i= mid ;
        int j = end ;
        int k = 0 ;
        int count = 0 ;
        while(i>=start&&j>mid) {
            if(elem[i] > elem[j]) {
                temp[k++] = elem[i--] ;
                count+=j-mid ;
            }
        }
    }
    //归并排序
    int inversePairsCore(vector<int>&elem, int start, int end, vector<int>& temp) {
        int inversion = 0 ;
        //左指针不能小于右指针
        if(start < end) {
            //计算中间的值
            int mid = (start+end)/2 ;
            inversion = inversePairsCore(elem, start, mid, temp) ;
            inversion += inversePairsCore(elem, start, mid, temp) ;
            inversion += Merge(elem, start, mid, end, temp) ;
        }
        return inversion ;
    }
};
int main() {
    vector<int>data ;
    while(1) {
        int a ;
        cin >> a ;
        if(a < 0) {
            break ;
        }
        data.push_back(a) ;
    }
    Solution ss ;
    cout << ss.InversePairs(data) << endl ;
    return 0;
}

