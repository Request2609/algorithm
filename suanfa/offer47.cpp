#include <iostream>
using namespace std ;

class Solution {
public:
    int Add(int num1, int num2)
    {
        int temp = 0 ;
        while(num2 != 0){
            //进行异或
            temp = num1^num2 ;
            num2 = (num1&num2)<<1 ;
            num1 = temp ;
        }
        return num1 ;
    }
};
int main()
{
    Solution ss ;
    cout << ss.Add(5, 7) << endl ;
    return 0;
}

