#include <iostream>
using namespace std ;

//每个物品的价值
int val[5] = {5,2,3,4,7} ;

//物品的体积
int weight[5] = {9,2,6,7,4} ;

//求在给定背包体积的情况下，求能装下的最大价值为多少？

int getVal(int& w)
{
    
    int sum = 0 ;
    for(int j=0; j<5; j++)
    {
        sum+=weight[j] ;
    }

    int arr[100] = {0} ;
    arr[weight[0]] = val[0];

    for(int i=1 ;i<5; i++)
    {
        int tmp = weight[i] ;
        for(int j=sum; j>=0 ;j--)
        {
            if(arr[j]!=0)
            {
                if(arr[j]+val[i] < w)
                {
                    arr[j+tmp] = max(arr[j+tmp],arr[j]+val[i]) ;
                    arr[tmp] = max(weight[tmp], arr[tmp]) ;
                }
            }
        }
    }

    int maxs = 0  ;
    for(int j=w; j>=0; j--)
    {
        if(maxs<arr[j])
        {   
            maxs = arr[j] ;
            w = j ;
        }
    }
    return maxs ;
}

int main()
{
    int w ;
    while(cin>>w)
    {
        int v = getVal(w) ;
        cout <<"质量：" <<w <<"_______最大价值："<< v <<endl ;
    }
    return 0;
}

