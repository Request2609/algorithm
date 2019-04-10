#include <iostream>
#include<vector>
#include<algorithm>
using namespace std ;

int n ;
vector<int>a ;
void getNum(int k, int sum, int& counts, vector<int>s, int& flag)
{
    if(sum > n)
    {
        flag =1 ;
        return ;
    }

    if(sum == n)
    {
        size_t len = a.size() ;
        for(size_t i=0;i<len;i++)
        {
            cout << a[i] ; 
            if(i != len-1)
                cout<<"+" ;
        }
        a.clear() ;
        cout <<endl ;
        flag = 1 ;
        counts ++ ;
        return ;
    }

    else
    {
        size_t len = s.size() ;
        for(size_t j=k; j< len; j++)
        {
                getNum(j+1, sum+s[j],  counts, s, flag) ;
                a.push_back(s[j]) ;

                while(1)
                {
                    if(j+1<len&&s[j]==s[j+1])
                    {
                        j++ ;
                    }

                    else
                    {
                        break ;
                    }
                }
        }
    }
}

int main()
{   
    int m ;
    cin>>n>>m ;

    vector<int>s ;
    while(m--)
    {
        int a ;
        cin>>a ;
        s.push_back(a) ;
    }

    //升序排列
    sort(s.rbegin(), s.rend());
    int counts = 0;
    int sum = 0;
    int k = 0;
    int flag = 0 ;
    getNum(k, sum, counts, s, flag) ;
    cout <<counts <<endl ;
    return 0;
}

