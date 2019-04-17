#include <iostream>
using namespace std ;
class Test
{
public:
    int score[100] ;
public:
    int& operator[](int i) ;
    int operator[](int i)const ;
};

int& Test::operator[](int i)
{
    cout <<"1" <<endl ;
    return  score[i] ;
}


int Test::operator[](int i)const
{
    cout<< "2" <<endl ;
    return score[i] ;
}

int main()
{
    Test tt  ;
    int n = 10;
    int i=0 ;
    
    while(n--)
    {
        tt.score[i]=n ;
        n-- ;
        i++ ;
    }

    int t = tt[1] ;
    t = 100 ;
    cout << (&t) <<endl ;
    cout << (&tt[1]) <<endl ;
    return 0;
}

