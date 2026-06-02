// Cycle Detection in Directed Graph using DFS
/*
Given a directed graph, determine if it contains a cycle.
Logic:
1. Perform a depth-first search (DFS) on the graph. During the DFS, keep track of the visited nodes using a state array (e.g., 0 for unvisited, 1 for visiting, and 2 for visited).
2. If you encounter a node that is currently being visited (state 1), it means there is a cycle in the graph. If you encounter a node that has already been fully visited (state 2), it means there is no cycle through that node.
Time Complexity: O(V + E) where V is the number of vertices and E is the number of edges in the graph.
*/

#include<bits/stdc++.h>
using namespace std;
bool cycle(int node,vector<vector<int>>&adj,vector<int>&visited){
       visited[node]=1;
       for(auto it:adj[node]){
           if(visited[it]==0){
             if(cycle(it,adj,visited)){
                  return true;
             }
           }else if(visited[it]==1){
                 return true;
           }
       }
     visited[node]=2;
     return false;
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
vector<int>vis(n,0);
for(int i=0;i<n;i++){
    if(!vis[i]){
        if(cycle(i,adj,vis)){
            cout<<"Have Cycle"<<'\n';
            return 0;
        }
    }
}
return 0;
}