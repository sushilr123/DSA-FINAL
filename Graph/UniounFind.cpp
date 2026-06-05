#include<bits/stdc++.h>
using namespace std;

// Union-Find (Disjoint Set Union) in C++
/*  
Union-Find is a data structure that keeps track of a set of elements partitioned into disjoint subsets. It provides two main operations:
1. Find: Determine which subset a particular element is in. This can be used for determining if two elements are in the same subset.
2. Union: Join two subsets into a single subset.
Logic:
1. Initialize a parent array where each element is its own parent (i.e., each element is in its own subset).
2. For the Find operation, use path compression to optimize the process of finding the root parent of an element.
3. For the Union operation, use union by rank or size to keep the tree flat, which helps in optimizing the Find operation.
Time Complexity: O(α(N)) for both Find and Union operations, where α(N) is the inverse Ackermann function, which grows very slowly and is practically constant for all reasonable values of N.
*/  

int find(int node,vector<int>&parent){
    if(parent[node]==node){
        return node;
    }
    return parent[node]=find(parent[node],parent);
}
void unionSet(int u,int v,vector<int>&parent,vector<int>&size){
    int pu=find(u,parent);
    int pv=find(v,parent);
    if(pu!=pv){
        if(size[pu]<size[pv]){
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        else{
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
    }
}


int main (){
int n,m;
cin>>n>>m;
vector<int>parent(n);
for(int i=0;i<n;i++){
    parent[i]=i;
}
vector<int>size(n,1);
vector<vector<int>>adj(n);
for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
for(int i=0;i<n;i++){
    for(auto it:adj[i]){
        unionSet(i,it,parent,size);
    }
}
for(int i=0;i<n;i++){
    cout<<parent[i]<<" ";
}
cout<<endl;
return 0;
}