/*
You have given an undirected graph with n nodes, and m edges between them. The goal is to add exactly one edge between two nodes such that the total number of connected components in the graph decreases.
Your task is to find out the number of ways to add such edge.
*/

#include<bits/stdc++.h>
using namespace std;

int find(int node,vector<int>&parent){
      if(node==parent[node])return node;
      return parent[node]=find(parent[node],parent);
}

void merge(int u,int v,vector<int>&parent,vector<int>&size){
           int x=find(u,parent);
           int y=find(v,parent);
           if(x==y)return ;
           if(size[x]<=size[y]){
             parent[x]=y;
             size[y]+=size[x];
           }else{
            parent[y]=x;
            size[x]+=size[y];
           }
}
int main (){
int n,m;
cin>>n>>m;
vector<int>parent(n);
vector<int>size(n,1);
for(int i=0;i<n;i++){
    parent[i]=i;
}
for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    merge(u,v,parent,size);
}
vector<int>res;
int sum=0;
for(int i=0;i<n;i++){
   if(i==parent[i]){
      res.push_back(size[parent[i]]);
      sum+=size[parent[i]];
   }
}
int ans=0;
for(int i=0;i<res.size();i++){
      sum-=res[i];
      ans+=sum*res[i];
}
cout<<ans<<'\n';
return 0;
}