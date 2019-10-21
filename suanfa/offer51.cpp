#include <iostream>
#include <unistd.h>
#include <map>
#include <algorithm>

using namespace std ;

class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        if(length == 0 || length == 1) {
            *duplication = -1;
            return false ;
        }
        sort(numbers, numbers+length) ;
        map<int, int>ls ;
        for(int i=0; i<length; i++) {
            if(ls.find(numbers[i]) == ls.end()) {
                ls[numbers[i]] = 0 ;
            }
            else {
                cout << numbers[i] << endl ;
                *duplication = numbers[i] ;
                return true ;
            }
        }
        *duplication = -1 ;
        return false ;
     }
};
int main() {
    int number[5] ;
    for(int i=0; i<5; i++) {
        cin >> number[i] ;
    }
    Solution ss ;
    int dd= 0 ;

    cout << ss.duplicate(number, 5, &dd) << endl ;  
    cout << dd << endl ;
    return 0;
}

