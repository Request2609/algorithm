#include <iostream>
#include <unistd.h>

using namespace std ;

class SealedClass {
public :
    static SealedClass* getInstance() {
        if(ss == NULL) {
            ss = new SealedClass() ;           
        }
        return ss ;
    }

private :
    static SealedClass* ss ;
    SealedClass() {}
    ~SealedClass() {}
} ;

SealedClass* SealedClass:: ss = NULL ;

/*
class Base : public SealClass {

} ;
*/

int main() {


    return 0;
}

