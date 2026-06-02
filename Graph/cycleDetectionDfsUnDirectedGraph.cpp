// Cycle Detection in Undirected Graph using DFS
/*
Given an undirected graph, determine if it contains a cycle. If a cycle exists, print the nodes that are part of the cycle.
Logic:
1. Perform a depth-first search (DFS) on the graph.
2. Keep track of the parent node for each visited node.
3. If you encounter a node that is already visited and is not the parent of the current node, it means there is a cycle in the graph.
Time Complexity: O(V + E) where V is the number of vertices and E is the number of edges in the graph.
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<int> cycleNodes;

bool dfs(int node,int par,
         vector<vector<int>>& adj,
         vector<int>& vis)
{
    vis[node]=1;

    for(int ng:adj[node])
    {
        if(ng==par)
            continue;

        if(!vis[ng])
        {
            parent[ng]=node;

            if(dfs(ng,node,adj,vis))
                return true;
        }
        else
        {
            cycleNodes.push_back(ng);

            int cur=node;

            while(cur!=ng)
            {
                cycleNodes.push_back(cur);
                cur=parent[cur];
            }

            cycleNodes.push_back(ng);

            return true;
        }
    }

    return false;
}

int main()
{
    int n,m;
    cin>>n>>m;

    vector<vector<int>> adj(n);

    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(n,0);
    parent.assign(n,-1);

    bool found=false;

    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            if(dfs(i,-1,adj,vis))
            {
                found=true;
                break;
            }
        }
    }

    if(found)
    {
        cout<<"Cycle Exists\n";

        reverse(cycleNodes.begin(),cycleNodes.end());

        for(int x:cycleNodes)
            cout<<x<<" ";

        cout<<"\n";
    }
    else
    {
        cout<<"No Cycle\n";
    }
}