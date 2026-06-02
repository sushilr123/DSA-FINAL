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

int main()
{
    int n,m;
    cin>>n>>m;

    vector<vector<int>> adj(n,vector<int>(m));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>adj[i][j];
        }
    }

    vector<vector<int>> dist(n,vector<int>(m,INT_MAX));

    int dx[4]={0,0,-1,1};
    int dy[4]={1,-1,0,0};

    deque<pair<int,int>> dq;

    dist[0][0]=0;
    dq.push_front({0,0});

    while(!dq.empty())
    {
        int x=dq.front().first;
        int y=dq.front().second;
        dq.pop_front();

        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];

            if(nx<0 || ny<0 || nx>=n || ny>=m)
                continue;

            int cost=(adj[x][y]==i)?0:1;

            if(dist[x][y]+cost<dist[nx][ny])
            {
                dist[nx][ny]=dist[x][y]+cost;

                if(cost==0)
                    dq.push_front({nx,ny});
                else
                    dq.push_back({nx,ny});
            }
        }
    }

    cout<<dist[n-1][m-1]<<'\n';
}