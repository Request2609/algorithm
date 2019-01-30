#include <iostream>
#include<iterator>
#include<vector>
using namespace std;
#define N 100
bool isSame(vector<char>ls,int start,char a){
    for(int i=start;i<(int)ls.size();i++) {
        if(a==ls[i]){
            return true;
        }
    }  
    return false;
}
void remove(vector<char>&ls){
    
    vector<char>::iterator iter ;
    for(iter=ls.begin();iter!=ls.end();iter++){
        ls.erase(iter);
        cout<<"sdssdwd"<<endl;
    }
    cout<<endl;
}
int main()
{

    string arr;
    vector<char>ls;
    int end =0;
    int len=0;
    int start=0;
    end=start;
    cin>>arr;
    while(1){
        if(end==(int)arr.length()){
            break;
        }

        if(ls.size()!=0){
            if(isSame(ls,start,arr[end])){
                if(len<(int)ls.size()){
                    len=(int)ls.size();
                }
                start++;
                end = start;
                remove(ls);
            }
            continue;
        }
        ls.push_back(arr[end++]);   
    }
    cout<<len;
    return 0;
}

