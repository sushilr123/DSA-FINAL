// 0-1 BFS Algorithm in C++
/*
Given a graph with edges that have weights of either 0 or 1, find the shortest path from a given source vertex to all other vertices in the graph.
Logic:
1. Use a deque (double-ended queue) to perform a modified breadth-first search (BFS).
2. When visiting a vertex, if the edge weight is 0, add the adjacent vertex to the front of the deque; if the edge weight is 1, add it to the back of the deque.
3. Update the distance to each adjacent vertex if a shorter path is found.
Time Complexity: O(V + E) where V is the number of vertices and E is the number of edges in the graph.
*/  

#include<bits/stdc++.h>
using namespace std;

void bfs01(vector<vector<pair<int,int>>>& adj,
           vector<int>& dis,
           int src)
{
    deque<int> dq;

    dis[src] = 0;
    dq.push_front(src);

    while(!dq.empty())
    {
        int node = dq.front();
        dq.pop_front();

        for(auto &it : adj[node])
        {
            int ng = it.first;
            int wt = it.second;

            if(dis[node] + wt < dis[ng])
            {
                dis[ng] = dis[node] + wt;

                if(wt == 0)
                    dq.push_front(ng);
                else
                    dq.push_back(ng);
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
int sc;
cin>>sc;
vector<int>dis(n,INT_MAX);
bfs01(adj,dis,sc);
for(int i=0;i<n;i++){
    cout<<dis[i]<<" ";
}
cout<<'\n';
return 0;
}