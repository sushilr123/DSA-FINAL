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
vector<int> a(n);
for(int i=0;i<n;i++){
    cin>>a[i];
}
int res=0;
for(int i=n/2;i<n;i++){
    res+=a[i];
}
cout<<res<<'\n';
return 0;
}