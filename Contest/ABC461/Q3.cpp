#include<bits/stdc++.h>
using namespace std;

int main (){
int n,k,m;
cin>>n>>k>>m;
priority_queue<pair<int,int>>pq;
for(int i=0;i<n;i++){
    int c,v;
    cin>>c>>v;
    pq.push({v,c});
}
long long ans=0;
set<int>used;
while(!pq.empty() && k>0){
    auto it=pq.top();
    pq.pop();
    int v=it.first;
    int c=it.second;
    if(k>m){
        if(used.find(c)==used.end()){
            ans+=(long long)v;
            k--;
            m--;
            used.insert(c);
        }
        else{
            ans+=(long long)v;
            k--;
        }
        
    }else{
        if(used.find(c)==used.end()){
            ans+=(long long)v;
            k--;
            m--;
            used.insert(c);
        }
    }
}
cout<<ans<<'\n';
return 0;
}