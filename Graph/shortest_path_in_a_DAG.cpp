// Shortest Path in a Directed Acyclic Graph (DAG)
/*
Given a directed acyclic graph (DAG) with weighted edges, find the shortest path from a given source vertex to all other vertices in the graph.

Logic:
1. Perform a topological sort of the DAG.
2. Initialize a distance array with infinity (or a very large number) for all vertices except the source vertex, which is initialized to 0.
3. Process the vertices in topologically sorted order. For each vertex, update the distances of its adjacent vertices if a shorter path is found through the current vertex.
Time Complexity: O(V + E) where V is the number of vertices and E is the number of edges in the graph.
*/

#include<bits/stdc++.h>
using namespace std;
void dfs(int node,vector<vector<pair<int,int>>>&adj,vector<int>&vis,vector<int>&topo){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it.first]){
            dfs(it.first,adj,vis,topo);
        }
    }
    topo.push_back(node);
}
int main (){
int n,m;
cin>>n>>m;
vector<vector<pair<int,int>>>adj(n);
for(int i=0;i<m;i++){
    int u,v,w;
    cin>>u>>v>>w;
    adj[u].push_back({v,w});
}
vector<int>topo;
vector<int>vis(n,0);
for(int i=0;i<n;i++){
    if(!vis[i]){
        dfs(i,adj,vis,topo);
    }
}
reverse(topo.begin(),topo.end());
vector<int>dist(n,INT_MAX);
int src;
cin>>src;
dist[src]=0;
for(auto it:topo){
    if(dist[it]!=INT_MAX){
        for(auto edge:adj[it]){
            int v = edge.first;
            int w = edge.second;
            dist[v] = min(dist[v], dist[it] + w);
        }
    }
}
for(int i=0;i<n;i++){
    if(dist[i]==INT_MAX){
        cout<<"INF"<<" ";
    }else{
        cout<<dist[i]<<" ";
    }
}
cout<<'\n';
return 0;
}