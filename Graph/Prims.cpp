// Prim's Algorithm in C++
/*
Given a connected, undirected graph with weighted edges, find the minimum spanning tree (MST) of the graph using Prim's algorithm.
Logic:
1. Start with an arbitrary vertex and add it to the MST.
2. While there are still vertices not included in the MST:
   a. Find the edge with the smallest weight that connects a vertex in the MST to a vertex outside the MST.
   b. Add the selected edge and the vertex it connects to the MST.
Time Complexity: O(E log V) where E is the number of edges and V is the number of vertices in the graph.

*/
#include<bits/stdc++.h>
using namespace std;
void primMST(vector<vector<pair<int,int>>>&adj,vector<int>&dist,vector<bool>&inMST){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,0});
    dist[0]=0;
    while(!pq.empty()){
        int node=pq.top().second;
        pq.pop();
        inMST[node]=true;
        for(auto it:adj[node]){
             int ng=it.first;
             int weight=it.second;
             if(!inMST[ng] && weight<dist[ng]){
                 dist[ng]=weight;
                 pq.push({dist[ng],ng});
             }
        }
    }
}
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
vector<int>dist(n,INT_MAX);
vector<bool>inMST(n,false);
primMST(adj,dist,inMST);
for(int i=0;i<n;i++){
    cout<<dist[i]<<" ";
}
cout<<'\n';
return 0;
}