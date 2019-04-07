#include <iostream>
#include<vector>
using namespace std ;

class Solution
{
public :
    void getNum(vector<int>arr)
    {
        if(arr.size() == 0)return ;
        int len = arr.size() ;

        vector<vector<int>> ss ;
        int k = 1 ;

        for(int i=0; i<len; i++)
        {
            vector<int>s ;
            for(int j=k; j<len; j++)
            {
                
                if(arr[j-1]<arr[j])
                {
                    s.push_back(arr[j-1]) ;
                    if(j == len-1)
                    {
                        k = j;
                        s.push_back(arr[j]) ;
                    }
                }

                else
                {
                    s.push_back(arr[j-1]) ;
                    k = j+1 ;
                    break ;
                }
            }
            
            int l = ss.size() ;
            int l_s = s.size() ;
            int cur_max=0 ; 
            if(l!=0)
            {
                cur_max =ss[0].size() ;     
            }

            if(l == 0 || l_s == cur_max)
            {
                ss.push_back(s) ;
            }

            else if(l_s > cur_max)
            {
                ss[0] = s ;
            }

            if( k == len-1 )
            {
                vector<int>ls ;
                if(cur_max == 1){
                    ls.push_back(arr[len-1]) ;
                    ss.push_back(ls) ;
                }    
                break ;
            }
        }
    
        for(size_t i=0; i< ss.size(); i++)
        {
            for(size_t j=0; j<ss[i].size(); j++)
            {
                cout << ss[i][j] <<"  " ; 
            }
            cout << endl ;
        }
    }
} ;
int main()
{
    vector<int> arr ;
    int a ;
    while(1)
    {
        cin >> a ;
        if(a == -1)
        {
            break ;
        }
        arr.push_back(a) ;
    }
    Solution s ;
    s.getNum(arr) ;
    return 0;
}

