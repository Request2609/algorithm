#include <iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
#define N 5
class Solution {
public:
    int count;
    bool makesquare(vector<int>& nums) {
        
        int len = (int)nums.size();
        if(len < 4) return false ;
        bool ca =false;
        int index=0;
        int maxs = getMax(nums,index);
        deleteNums(index,nums);
        len = len-1;
        int _map[5][5]; 
        int l =sqrt(len);
        int k;
        int flags[5][5]={{0}};
        if(len%l==0&&len!=l*l){
            getMap(l+1,l,_map,nums,flags);
            print(l+1,l,_map);
            cout<<"++++++++++++++"<<endl;
            print(l+1,l,flags);
            cin>>k;
            search(ca,maxs,l+1,l,_map,flags);
        }

        else{
            getMap(l+1,l+1,_map,nums,flags);
            print(l+1,l+1,_map);
            cout<<"+++++++++++++"<<endl;
            print(l+1,l+1,flags);
            cin>>k;
            search(ca,maxs,l+1,l+1,_map,flags);
        }
        return ca; 
    }
    
    void Dfs(bool &ca,int i,int j,int _map[5][5],int sum,int flags[5][5],int maxs){
        
        
        flags[i][j]=1;
            sum+=_map[i][j] ;
            if(sum>maxs){
                flags[i][j]=0;
                return ;
            }
            else if(sum==maxs){
                ca = true;
                count++;
                return ;
            }

            else{

                if(ca!=true){
                if(!flags[i][j+1]&&_map[i][j+1]!=-1)
                    Dfs(ca,i,j+1,_map,sum,flags,maxs);
                if(!flags[i+1][j]&&_map[i+1][j]!=-1)
                    Dfs(ca,i+1,j,_map,sum,flags,maxs);
                if(!flags[i][j-1]&&_map[i][j-1]!=-1)
                    Dfs(ca,i,j-1,_map,sum,flags,maxs);
                if(!flags[i-1][j]&&_map[i-1][j]!=-1)
                    Dfs(ca,i-1,j,_map,sum,flags,maxs);
                }
                    
            }
            
        }
    void search(bool &ca,int maxs,int l,int w,int _map[5][5],int flags[5][5]){
            count =1 ;
            for(int i = 1 ; i<=l ; i++){
                for(int j = 1 ; j <= w ; j++){
                    int sum =0;
                    ca = false;
                    if(_map[i][j]== -1){
                        break ;
                    }
                    Dfs(ca,i,j,_map,sum,flags,maxs);
                    if(ca==false){
                        break;
                    }
                }
            }
            if(count!=4||!go(l,w,flags)){
                ca = false;
            }
    }

    bool go(int l,int w,int flags[5][5]){

        for(int i= 1;i<=l;i++){
            for(int j=1;j<=w;j++){
                if(flags[i][j]!=1){
                    return false ;
                }
            }
        }
        return true;
    }

    void print(int l,int w,int _map[][5]){
            
        for(int i = 0 ;i <= l+1 ;i++){
            for(int j = 0 ;j <= w+1 ; j++){
                cout<<_map[i][j]<<"  ";
            }
            cout<<endl;
        }
    }

    void getMap(int l,int w ,int _map[][5],vector<int>& nums,int flags[5][5]){
        
        int count =0 ;

        for(int i = 0 ; i <= l+1 ; i++){
            for(int j = 0 ; j<= w+1 ; j++){
                if(i==0||j==0||i==l+1||j==w+1){
                    _map[i][j] = -1;
                }
                else{
                    
                    if(count==(int)nums.size()-1){
                        _map[i][j]=-1 ;
                        flags[i][j]=1;
                        continue ;
                    }
                    _map[i][j] = nums[count];
                    count++;
                    
                }
            }
        }
    }
        
        
    
    void deleteNums(int index,vector<int>& nums){
        vector<int>::iterator it ;
        int i =0 ;
        for(it = nums.begin();it!=nums.end();it++,i++){
            if(i==index){
                nums.erase(it);
                break;
            }
        }
    }
    
    
    int getMax(vector<int>& nums,int &index){
        
        sort(nums.begin(),nums.end());
        index = (int)nums.size()-1;
        return nums[index];
    }
    
};
int main()
{

    vector<int>s ;
    int a ;
    while(cin>>a){
        if(a==-1)break ;
        s.push_back(a);
    }
    cout<<s.size()<<"----------------------"<<endl;
    Solution ss ;
    ss.makesquare(s);
    std::cout << "Hello world" << std::endl;
    return 0;
}

