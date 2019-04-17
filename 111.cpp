#include <iostream>

using namespace std ;

bool check(int num)
{
    int s[11] ;
    int cur  =  0;
    int sum=0 ;
    while(num>0)
    {
        s[cur] = num%10 ;  
        sum+=s[cur++] ;
        num=num/10 ;
    }

    if(sum%2!=0)return false ;
    int t = sum/2 ;
    bool ok[42] ={0} ;
    
    ok[s[0]] = true ;
    for(int i=1;i<cur;i++)
    {
        int v = s[i] ;
        for(int j=41;j>=0;j--)
        {
            if(ok[j]&&j+v<=41)
            {
                ok[j+v] = true ;
            }
        }
    }
        
    if(ok[t])
    {
        return true ;
    }

    return false ;
}

int main()
{
    int res = 0;
    double start ,end ;
    int  r, l ;
    cin>>l>>r ;
    start = clock() ;
    for(int i=l;i<=r;i++)
    {
        if(check(i))
        {
            cout << i <<endl ;
            res ++ ;
        }
    }
    end =clock() ;
    cout << res <<endl ;

    cout <<"运行时长:"<< start-end <<endl ;
    return 0;
}

