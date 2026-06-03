#include<bits/stdc++.h>
using namespace std;
//void solution(){
//}
int main (){
int n,m;
cin>>n>>m;
vector<vector<int>>adj(n);
vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
for(int i=0;i<m;i++){
    int u,v,w;
    cin>>u>>v>>w;
    adj[u].push_back(v);
    adj[v].push_back(u);
    dist[u][v]=w;
    dist[v][u]=w;
}

for(int i=0;i<n;i++){
    dist[i][i]=0;
}
// Floyd-Warshall algorithm
for(int k=0;k<n;k++){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
}
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(dist[i][j]==INT_MAX){
            cout<<"INF"<<" ";
        }else{
            cout<<dist[i][j]<<" ";
        }
    }
    cout<<'\n';
}
return 0;
}