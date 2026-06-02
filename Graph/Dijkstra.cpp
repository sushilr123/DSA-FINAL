// Dijkstra's Algorithm in C++
/*
Given a directed graph with non-negative edge weights, find the shortest path from a given source vertex to all other vertices in the graph.
Logic:
1. Use a priority queue (min-heap) to efficiently retrieve the vertex with the smallest distance.
2. Initialize distances from the source to all vertices as infinite and distance to the source itself as 0.
3. While the priority queue is not empty:
   a. Extract the vertex with the smallest distance (let's call it u).
   b. For each adjacent vertex v of u, if the distance to u plus the weight of the edge (u, v) is less than the current distance to v, update the distance to v and add it to the priority queue.   
Time Complexity: O((V + E) log V) where V is the number of vertices and E is the number of edges in the graph.
*/

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