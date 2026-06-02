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