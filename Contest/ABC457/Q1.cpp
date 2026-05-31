#include<bits/stdc++.h>
using namespace std;
//void solution(){
//}
int main (){
int n;
cin>>n;
vector<int>res;
for(int i=0;i<n;i++){
    int r;
    cin>>r;
    res.push_back(r);
}
int index;
cin>>index;
cout<<res[index-1]<<'\n';
return 0;
}