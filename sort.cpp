#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<int>a ;
    int b ;
    while(cin>>b){
        if(b==-1)break;
        a.push_back(b);
    }
    sort(a.begin(),a.end());

    for(auto s :a){
        cout<<s<<endl;
    }
   // cout<<a.size()<<endl;
    cout<<"++++++++"<<a[5]<<endl;
   cout<<a[(int)a.size()-1]<<endl;
    return 0;
}

