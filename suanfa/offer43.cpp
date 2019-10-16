#include <iostream>
#include <vector>
#include <string>
using namespace std ;

class Solution {
public:
    string ReverseSentence(string str) {        
        if(str.empty()) {
            return "" ;
        }
        vector<string>ls ;
        getEachWord(str, ls) ;
        string ss = " " ;
        if(ls.empty()) {
            return ss ;
        }
        ss = "" ;
        int len = ls.size() ;
        for(int i=len-1; i>=0; i--) {
            ss+=ls[i] ;
            if(i != 0) {    
                ss+=' ' ;
            }
        }
        return ss ;
    }
    void print(vector<string>s) {
        int len = s.size() ;
        cout << len << endl ;
        for(int i=0; i<len; i++) {
            cout << s[i] << endl;
        }
        cout << endl ;
    } 

    void getEachWord(const string& s, vector<string>&ls) {
        int len = s.size() ;
        int index= 0 ;
        while(index < len) {
            string tmp="" ;
            while(s[index] != ' '&&index < len) {
                tmp+=s[index] ;
                index++ ;
            }
            if(!tmp.empty()) {
                ls.push_back(tmp) ;
            }
            while(s[index] == ' ') {
                index++ ;
            }
        }
    }
};
int main()
{
    string ss ;
    getline(cin, ss) ;
    Solution sl ;
    cout << sl.ReverseSentence(ss) << endl ;
    return 0;
}

