#include <iostream>
#include <map>
#include <vector>
using namespace std ;

class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string>ls ;
        getVector(ls, str, 0) ;   
        return ls ;
    }
    void getVector(vector<string>&ls, string str, int k) {
        int len = str.size() ;
        if(len-1 == k) {
            string ss = str ;
            ls.push_back(ss) ;
        }
        for(int i=k; i<len; i++) {
            if(i!=k && str[i] == str[k]) {
                continue ;
            }
            swap(str[i], str[k]) ;
            getVector(ls, str, k+1) ;
            swap(str[i], str[k]) ;
        }
    }

    void swap(char& c1, char& c2) {
        char c = move(c1) ;
        c1 = move(c2) ;
        c2 = move(c) ;
    }
};
int main() {
    string aa ;
    cin >> aa ;
    Solution ss ;
    vector<string>ls = ss.Permutation(aa) ;
    int len= ls.size();
    for(int i=0; i<len; i++) {
        cout << ls[i] << endl ;
    }
    return 0;
}

