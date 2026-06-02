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