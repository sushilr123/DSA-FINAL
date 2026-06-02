#include<bits/stdc++.h>
using namespace std;

int main (){
int n,m;
cin>>n>>m;
vector<pair<int,pair<int,int>>>edges;
for(int i=0;i<m;i++){
    int u,v,w;
    cin>>u>>v>>w;
    edges.push_back({u,{v,w}});
}
int src;
cin>>src;
vector<int>dist(n,INT_MAX);
dist[src]=0;

for(int i=0;i<n-1;i++){
    bool flag=false;
    for(int j=0;j<m;j++){
        int u=edges[j].first;
        int v=edges[j].second.first;
        int w=edges[j].second.second;
        if(dist[u]!=INT_MAX && dist[v]>dist[u]+w){
            dist[v]=dist[u]+w;
            flag=true;
        }
    }
    if(!flag){
        break;
    }
}
set<int>nodes;
bool flag=false;
for(int j=0;j<m;j++){
        int u=edges[j].first;
        int v=edges[j].second.first;
        int w=edges[j].second.second;
        if(dist[u]!=INT_MAX && dist[v]>dist[u]+w){
            dist[v]=dist[u]+w;
            nodes.insert(u);
            nodes.insert(v);
            flag=true;
        }
    }
    if(flag){
        cout<<"Have Negative Cycle"<<'\n';
        cout<<"Node that is the part of negative cycle"<<'\n';
for(auto it:nodes){
    cout<<it<<" ";
}
cout<<'\n';
        return 0;
    }
for(int i=0;i<n;i++){
    cout<<dist[i]<<'\n';
}
cout<<'\n';
cout<<"Node that is the part of negative cycle"<<'\n';
for(auto it:nodes){
    cout<<it<<" ";
}
cout<<'\n';
return 0;
}