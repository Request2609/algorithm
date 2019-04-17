#include <iostream>
#include<vector>
#include<string>
using namespace std ;

int getLongest(string s) ;
int isContain(vector<char>ls, char i) ;
void remove(int lo, vector<char>s) ;

int main()
{
    string s ;
    cin >> s ;
    
    cout << getLongest(s) << endl ;
    return 0;
}

int getLongest(string s)
{
    int sta = 0 ;
    int l = sta+1 ;
    vector<char>ls ;
    if(s.size()==0)
    {
        return 0 ;
    }
    if(s.size() ==1)
    {
        return 1;
    }
    int ll ;
    ls.push_back(s[sta]) ;
    int len = s.size() ;
    for(int i=l; i<len; i++)
    {
        if((ll = isContain(ls, s[i])) == -1) 
        {
            ls.push_back(s[i]) ;
        }
        remove(ll, ls);
    }
    return ls.size() ;
}

int isContain(vector<char>ls, char ch)
{
    int len = ls.size();
    for(int k=0; k<len; k++) 
    {
        if(ls[k] == ch) 
        {
            return k ;
        }
    }
    return -1 ;
}

void remove(int lo, vector<char>ls)
{
    int i = 0 ;
    vector<char>::iterator iter ;
    for(iter = ls.begin();i!=lo+1;iter++)
    {
        ls.erase(iter) ;
        i++;
    }
}
