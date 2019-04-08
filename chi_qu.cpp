#include <iostream>

int main()
{
    int a[] = {5,1,3,5,10,7,4,9,2,8} ;
    
    int l = 0 ;
    int r = 1 ;
    int min_len = -1 ;

    while(l<r)
    {
        int sum = 0 ;
        int flag = 0 ;
        int i ;
        int len = 0;
        for(i=l; i<r; i++) 
        {
            sum += a[i] ;
            if(sum == 15)
            {
                flag = 1 ;
                min_len = i-l ;
                break ;
            }
        }

        if(sum<15)
        {
            len += r-l ;
            l = i ;
            r++ ;
        }
        
    }
    return 0;
}

