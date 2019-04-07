#include <iostream>
#include<vector>
#include<algorithm>
using namespace std ;

vector<int>zhong_shu ;
vector<int>shu_liang ;
int shu_zi ;
int counts ;

int  getMid(vector<int>arr, int l, int r)
{
    return  arr[(r+l)/2] ;
}

//记录中间节点的数量
int getLeftCount(vector<int>arr, int mid, int m_index)
{
    int i = m_index ;
    for(i = m_index; i >=0; i--)
    {
        if(mid == arr[i])
        {
            counts++ ;
        }
        else
        {
            break ;
        }
    }
    return i ;
}

void process(vector<int>arr, int l, int r)
{
    
    cout <<r<<"------"<<l<<endl ;
    if(l == r||r<l)
    {
        return ;    
    }

    int l_index = l ;
    int r_index = r ;
    int m_index =(l+r)/2 ;
    //获取中间的数,个数要是为奇数的话，就取中间那个数
    //否则取中间两个数中最小的那个
    int mid = arr[m_index] ;
    int index = getLeftCount(arr, mid, m_index) ;
    int i = m_index+1 ;
    //如果中间数字的靠左边的总数量，多于左边与中间数字不等的数字的总数量
    if(index-l_index+1 > m_index-index)
    {   

        for(i=m_index+1; i<=r_index; i++)
        {
            if(arr[i] == mid)
            {
                counts ++ ;
            }
        }
        zhong_shu.push_back(mid) ;
        shu_liang.push_back(counts) ;
        counts = 0 ;
        l_index = i ;
        process(arr, l_index, r_index) ;
    }

    //如果小于非中间数字的总数量
    else 
    {
        for(i=m_index+1; i<=r_index; i++)
        {
            if(arr[i] == mid)
            {
                counts ++ ;
            }
        }
        zhong_shu.push_back(mid) ;
        shu_liang.push_back(counts) ;
        counts = 0 ;
        r_index = index ; 
        process(arr, l_index, r_index) ;   
        l_index = i ;
        r_index = r ;
        process(arr, l_index, r_index) ;
    }
}

int main()
{
    int n ;
    vector<int>nums ;
    int s ;
    cin >> n ;
    while(n--)
    {
        cin >> s ;
        nums.push_back(s); 
    }
    sort(nums.begin(), nums.end()) ;
    //设置左右边界
    int l = 0 ,r = nums.size() - 1 ;
    process(nums, l, r) ;
    
    for(size_t i= 0;i<zhong_shu.size();i++)
    {   
        cout << zhong_shu[i]  <<"   " << shu_liang[i] << endl ;   
    }

    return 0;
}

