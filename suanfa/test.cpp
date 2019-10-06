#include <iostream>
#include <memory>
#include <vector>
using namespace std ;

int main()
{
    shared_ptr<vector<int>>s = make_shared<vector<int>>() ;
    s->push_back(1) ;
    s->push_back(2) ;
    cout << (*s)[0] << endl ;
    cout << s->operator[](1) << endl ; 
    return 0;
}

