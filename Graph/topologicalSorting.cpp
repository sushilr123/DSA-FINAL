// Topological Sorting in C++
/*
Given a directed acyclic graph (DAG), perform a topological sort of the vertices.
Logic:
1. Calculate the in-degree (number of incoming edges) for each vertex.
2. Initialize a queue and enqueue all vertices with an in-degree of 0 (i.e., vertices with no dependencies).
3. While the queue is not empty:
   a. Dequeue a vertex from the queue and add it to the topological order.
   b. For each adjacent vertex of the dequeued vertex, decrease its in-degree by 1. If the in-degree of an adjacent vertex becomes 0, enqueue it.
4. If the topological order contains all vertices, return the order; otherwise, the graph has a cycle and a topological sort is not possible.
Time Complexity: O(V + E) where V is the number of vertices and E is the number of edges in the graph.
*/

#include<bits/stdc++.h>
using namespace std;

int main (){
int n,m;
cin>>n>>m;
vector<vector<int>>adj(n);
for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
}
vector<int>indegree(n,0);
for(int i=0;i<n;i++){
    for(auto it:adj[i]){
        indegree[it]++;
    }
}
queue<int>q;
for(int i=0;i<n;i++){
    if(indegree[i]==0){
        q.push(i);
    }
}
vector<int>topo;
while(!q.empty()){
    int node=q.front();
    q.pop();
    topo.push_back(node);
    for(auto it:adj[node]){
        indegree[it]--;
        if(indegree[it]==0){
            q.push(it);
        }
    }
}
for(auto it:topo){
    cout<<it<<" ";
}
return 0;
}