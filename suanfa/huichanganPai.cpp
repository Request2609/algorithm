#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;

//贪心算法:会场安排问题
class node {

public :
    bool operator>(node t) {
        return x>t.x ;
    }
    int x, y ;
};

int cmp_func(node a, node b)
{
    if(a.y < b.y)
        return true;
    return false;
}

int main() {
    vector<node> ls ;
    while(1) {
        node n ;
        cin >> n.x >> n.y ;
        if(n.x==-1 ||n.y == -1) {
            break ;
        }
        ls.push_back(n) ;
    }
    sort(ls.begin(), ls.end(), cmp_func) ;
    int len = ls.size() ;
    int count = 1 ;
    int end = ls[0].y ;
    for(int i=1; i<len; i++) {
        if(end < ls[i].x) {
            count ++ ;
            end = ls[i].y ;
        }
    }
    cout << count << endl ;
    return 0;
}

