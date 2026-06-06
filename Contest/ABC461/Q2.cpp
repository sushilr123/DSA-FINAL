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
vector<int>arr(n);
vector<int>brr(n);
for(int i=0;i<n;i++){
    cin>>arr[i];
}
for(int i=0;i<n;i++){
    cin>>brr[i];
}

for(int i=0;i<n;i++){
    if(arr[brr[i]-1]!=(i+1)){
        cout<<"No"<<'\n';
        return 0;
    }
}
cout<<"Yes"<<'\n';
return 0;
}