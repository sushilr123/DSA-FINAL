#include<bits/stdc++.h>
using namespace std;

int main (){
int n,m;
cin>>n>>m;
vector<vector<pair<int,int>>>adj(n);
for(int i=0;i<m;i++){
    int u,v,w;
    cin>>u>>v>>w;
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
}
int sc;
cin>>sc;
vector<int>dist(n,INT_MAX);
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
pq.push({0,sc});
dist[sc]=0;
while(!pq.empty()){
    int node=pq.top().second;
    int val=pq.top().first;
    pq.pop();
    for(auto it:adj[node]){
         int ng=it.first;
         int weight=it.second;
         if(val+weight<dist[ng]){
             dist[ng]=val+weight;
             pq.push({dist[ng],ng});
         }
    }
}
for(int i=0;i<n;i++){
    cout<<dist[i]<<" ";
}
cout<<'\n';
return 0;
}