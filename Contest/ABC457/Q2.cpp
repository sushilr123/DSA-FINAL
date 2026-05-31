#include<bits/stdc++.h>
using namespace std;
//void solution(){
//}
int main (){
int n;
cin>>n;
vector<vector<int>>res(n);
for(int i=0;i<n;i++){
    int r;
    cin>>r;
    for(int j=0;j<r;j++){
       int x;
       cin>>x;
       res[i].push_back(x); 
    }
}
int p,q;
cin>>p>>q;
cout<<res[p-1][q-1]<<'\n';
return 0;
}