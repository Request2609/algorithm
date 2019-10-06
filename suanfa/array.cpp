#include <iostream>
#include <vector>

using namespace std ;

bool find(vector<vector<int>>ls , int s) {

    int col, row ;
    row = ls.size() ;
    if(row == 0) {
        return false ;
    }
    col = ls[0].size() ;
    int i= 0, j=col-1;
    while(i<row && j>=0) {
        if(ls[i][j] == s) {
            return true ;
        }
        else if(ls[i][j] < s) {
            i++ ;
        }
        else {
            j-- ;
        }
    }
    return false ;
}
int main()
{
    int a1[] = { 1, 2, 8, 9, };
    int a2[] = { 2, 4, 9, 12, };
    int a3[] = { 4, 7, 10, 13, };
    int a4[] = { 6, 8, 11, 15, };
    vector<vector<int>> array;
    array.push_back(vector<int>(a1, a1 + 4));
    array.push_back(vector<int>(a2, a2 + 4));
    array.push_back(vector<int>(a3, a3 + 4));
    array.push_back(vector<int>(a4, a4 + 4));
    cout << find(array, 20) << endl ;
}
        
