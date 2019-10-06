#include <iostream>
#include <vector>
using namespace std ;
//装在问题回溯法
//现将一艘船尽量装满，然后将剩下的货物撞到另一个船上

int cw ;
int bestw = INT32_MIN; 
int c ;
void getBest(vector<int>&ls, int index) {
    int len = ls.size() ;
    if(len <= index) {//到达叶节点
        if(cw > bestw) {
            bestw = cw ;
            cout << bestw << endl ;
        }
        return ;
    }
    
    if(cw+ls[index] <= c) {
        cw += ls[index] ;
        getBest(ls, index+1) ; 
        cw -= ls[index] ;
    }
    getBest(ls, index+1) ;
}

int main() {
    int c1, c2 ;
    //船的容量分别是
    cin >> c1 >> c2 ;
    vector<int>ls ;
    int sum = 0 ;
    while(1) {
        int a ;
        cin >> a ;
        if(a<0) break ;
        sum += a ;
        ls.push_back(a) ;
    }
    c = c1 ;
    getBest(ls, 0) ;
    if(sum - c1 < c2)  {
        cout << "NO" << endl ;
    }
    else {
        cout << "YES" << endl ;
    }
    cout << bestw << endl ;
    return 0;
}

