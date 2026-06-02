// Topological Sort using DFS in C++
/*
Given a directed acyclic graph (DAG), perform a topological sort of the vertices.
Logic:
1. Perform a depth-first search (DFS) on the graph. When visiting a vertex, recursively visit all its adjacent vertices that have not been visited yet.
2. After visiting all adjacent vertices, add the current vertex to a stack (or a list).
3. Once all vertices have been visited, the stack will contain the vertices in reverse topological order. Pop all elements from the stack to get the topological sort.
Time Complexity: O(V + E) where V is the number of vertices and E is the number of edges in the graph.
*/

#include<bits/stdc++.h>
using namespace std;
void dfs(int node,vector<vector<int>>&adj,vector<int>&vis,vector<int>&topo){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it,adj,vis,topo);
        }
    }
    topo.push_back(node);
}
int main (){
int n,m;
cin>>n>>m;
vector<vector<int>>adj(n);
for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
}
vector<int>topo;
vector<int>vis(n,0);
for(int i=0;i<n;i++){
    if(!vis[i]){
        dfs(i,adj,vis,topo);
    }
}
for(auto it:topo){
    cout<<it<<" ";
}
return 0;
}