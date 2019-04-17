#include <iostream>
using namespace std ;

class C1{
public :

    virtual void func() = 0 ;
    virtual void foo() = 0 ;
};

class C{
    int a ;
public:
    virtual void func() = 0 ;
    void append(){}
};

class B:public C{

public :
    void func() {}
};

class D{
public :
    void func() {}
};

class D1{

public:
    void func() {}
    void foo(){}
};

int main()
{
    cout <<"sizeof C:"<<sizeof(C) <<endl;

    cout <<"sizeof C1:"<<sizeof(C1) <<endl;
    cout <<"sizeof B:"<<sizeof(B) <<endl;

    cout <<"sizeof D:"<<sizeof(D) <<endl;
    cout <<"sizeof D1:"<<sizeof(D1) <<endl;
        return 0;
}

