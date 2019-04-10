#include <iostream>
#include<algorithm>
#include<vector>
using namespace std ;

int main()
{
    int a  ;
    vector<int>s ;
    while(1)
    {
        cin>>a ;
        if(a == -1)break ;
        s.push_back(a) ;
    }

    sort(s.begin(), s.end()) ;
    for(size_t i= 0; i< s.size(); i++)
    {
        cout << s[i] <<endl ;
    }
    return 0;
}

