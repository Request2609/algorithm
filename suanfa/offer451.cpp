#include <iostream>
using namespace std ;
class Solution {
public:
    int LastRemaining_Solution(unsigned int n, unsigned int m)
    {
        if(n < 1 || m < 1)
        {
            return -1;
        }
        else if(n == 1)
        {
            return 0;
        }
        else
        {
            return (LastRemaining_Solution(n-1,m)+m)%n;
        }
    }
};
int main()
{
    Solution ss ;
    cout <<  ss.LastRemaining_Solution(6, 6) << endl ;
    return 0;
}

