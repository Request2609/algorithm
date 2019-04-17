#include <iostream>
 using namespace std ;

int len ; 
int flag =0 ;
void getwei(int num, int& sum, int* a)
{
    
    int i = 0 ;
    while(num>0)
    {
        a[i] = num%10 ;
        sum += a[i++] ;
        num /=10 ;
    }
    len = i ;
}

void  check(int* a, int index, int middle)
{
    int tmp = middle-a[index] ;
    
    if(index >= len)
    {
        return ;
    }
    if(tmp == 0)
    {
        flag = 1 ;
        return ;
    }

    else if(tmp < 0)
    {
        check(a, index+1, middle) ;
    }

    else
    {
        check(a, index+1, middle-a[index]) ;
    }
}
void  check1(int* a, int index, int middle)
{
    int tmp = middle-a[index] ;
    
    if(index >= len)
    {
        return ;
    }
    cout << middle <<"========" <<a[index]<<"====" <<endl ;

    if(tmp == 0)
    {
        flag = 1 ;
        return ;
    }

    else if(tmp < 0)
    {
        check1(a, index+1, middle) ;
    }

    else
    {
        
        check1(a, index+1, middle-a[index]) ;
    }
}

void func(int m, int n)
{
    
    int counts = 0;

    for(int i=m; i<=n; i++)
    {
        int sum = 0 ;
        int a[100]={0} ;

        flag  = 0 ;
        getwei(i,sum,a) ;

        if(sum%2)
        {
            continue ;
        }
            
        sum = sum/2-a[0] ;

        if(i == 99871)
        for(int k= 1; k< len; k++)
        {
            
           check1(a, k, sum) ;
           if(flag == 1)
           {
               cout <<flag <<endl ;
                break ;
            }
        }

        if(flag == 1)
        { 
            cout << i << endl ;
            counts ++ ;
        }
    }

    cout << "神奇数个数:"<<counts<<endl ;
}
int main()
{
    int m, n ;
    cin>>m>>n ;
    getchar() ;
    int start = clock() ;
    func(m, n) ;

    int end =clock() ;
    cout <<"总用时："<<end-start<<endl ;
    return 0;
}

