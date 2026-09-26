#include<bits/stdc++.h>
using namespace std;

int main (){
int n,k;
cin>>n>>k;
map<int,int> a;
for(int i=0;i<n;i++){
    int x;
    cin>>x;
    a[x]++;
}
int res=0;
int maxi=0;
for(auto i:a){
    if(i.second>=maxi){
        maxi=i.second;   
    }
}
for(auto i:a){
    if(i.second==maxi || i.second==maxi-1){
        res++;
    }
}
cout<<res<<'\n';
return 0;
}