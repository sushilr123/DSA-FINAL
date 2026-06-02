// Bellman-Ford Algorithm in C++
/*
Given a directed graph with possibly negative weight edges, find the shortest path from a given source vertex to all other vertices in the graph. If there is a negative weight cycle reachable from the source, report it.
Logic:
1. Initialize distances from the source to all vertices as infinite and distance to the source itself as 0.
2. Relax all edges |V| - 1 times, where |V| is the number of vertices in the graph. For each edge (u, v) with weight w, if the distance to u plus w is less than the distance to v, update the distance to v.
3. After the |V| - 1 iterations, check for negative weight cycles by trying to relax the edges one more time. If any distance can still be reduced, it means there is a negative weight cycle in the graph.
Time Complexity: O(V * E) where V is the number of vertices and E is the number of edges in the graph.
*/
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