#include<bits/stdc++.h>
using namespace std;

int findSet(int node, vector<int>& parent)
{
    if(parent[node]==node)
        return node;

    return parent[node]=findSet(parent[node],parent);
}

void unionSet(int u,int v,
              vector<int>& parent,
              vector<int>& sz)
{
    int pu=findSet(u,parent);
    int pv=findSet(v,parent);

    if(pu==pv) return;

    if(sz[pu] < sz[pv])
    {
        parent[pu]=pv;
        sz[pv]+=sz[pu];
    }
    else
    {
        parent[pv]=pu;
        sz[pu]+=sz[pv];
    }
}

int main()
{
    int n,m;
    cin>>n>>m;

    vector<int> parent(n);
    vector<int> sz(n,1);

    for(int i=0;i<n;i++)
        parent[i]=i;

    vector<tuple<int,int,int>> edges;

    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;

        edges.push_back({w,u,v});
    }

    sort(edges.begin(),edges.end(),greater<tuple<int,int,int>>());

    long long ans=0;

    for(auto it:edges)
    {
        int w=get<0>(it);
        int u=get<1>(it);
        int v=get<2>(it);
        int pu=findSet(u,parent);
        int pv=findSet(v,parent);

        if(pu!=pv)
        {
            ans += 1LL * sz[pu] * sz[pv] * w;
            unionSet(u,v,parent,sz);
        }
    }

    cout<<ans<<"\n";
}