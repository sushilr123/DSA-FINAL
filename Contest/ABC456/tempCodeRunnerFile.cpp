#include<bits/stdc++.h>
using namespace std;
void solution(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int w;
    cin>>w;
    vector<string>hd(w);
    for(int i=0;i<n;i++){
        cin>>hd[i];
    }
    vector<bool>visited(n+1,false);
    queue<pair<int,int>>q;
    for(int i=1;i<=n;i++){
        if(hd[i][0]=='o'){
            q.push({i,1});
            visited[i]=true;
        }
    }

    bool flag=false;
    while(!q.empty()){
        int node= q.front().first;
        int dist= q.front().second;
        q.pop();
        for(auto it:adj[node]){
            if(hd[it][dist%w]=='o' && !visited[it]){
                visited[it]=true;
                q.push({it,dist+1});
            }else if(hd[it][dist%w]=='o' && visited[it]){
                flag=true;
                break;
            }
        }
    }
    if(flag){
        cout<<"Yes"<<'\n';
    }else{
        cout<<"No"<<'\n';
    }
}
int main (){
int t;
cin>>t;
while(t--){
solution();
}
return 0;
}