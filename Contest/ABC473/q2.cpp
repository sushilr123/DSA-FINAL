#include<bits/stdc++.h>
using namespace std;
//void solution(){
//}
int main (){
//int t;
//cin>>t;
//while(t--){
//solution();
//}
int n;
cin>>n;
map<int,int> a;
for(int i=0;i<n;i++){
    int x;
    cin>>x;
    a[x]++;
}
int res=0;
for(auto i:a){
    if(i.second%2==1){
        res+=i.first;
    }
}
cout<<res<<'\n';
return 0;
}