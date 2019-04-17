#include <iostream>
using namespace std ;

class p{
public :
    void func(){
        cout <<"person func "<<endl ;
    }
    virtual void foo(){
        cout <<"person foo" <<endl ;
    }
};
class tmp{
public :
    virtual void func()=0 ;
    virtual void foo()=0 ;
};

class s:public tmp{

public :

public :
    /*void foo(){
        cout <<"son foo" <<endl ;
    }*/
    void func(){
        cout <<"son func" <<endl ;
    }

};
int main()
{
    s son ;
    //将子类转换成一个父类对象
    p *per = (p*)&son ;

   // per->foo() ;
    per->func() ;
    cout << "----------------------" <<endl ;
    p pe;
    s* so = (s*)&pe ;
    
    //so->foo() ;
    so->func() ;
    return 0;
}

