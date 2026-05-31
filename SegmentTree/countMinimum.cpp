#include<bits/stdc++.h>
using namespace std;
void build(int index,int l,int r,vector<pair<int,int>>&tree,vector<int>&arr){
         if(l==r){
            tree[index]={arr[l],1};
            return;
         }
         int mid=(l+r)/2;
         build(index*2,l,mid,tree,arr);
         build(index*2+1,mid+1,r,tree,arr);
         if(tree[2*index].first==tree[2*index+1].first){
             tree[index]={tree[2*index].first,tree[index*2].second+tree[index*2+1].second};
         }else if(tree[2*index].first<tree[2*index+1].first){
                tree[index]={tree[2*index].first,tree[2*index].second};

         }else{
                tree[index]={tree[2*index+1].first,tree[2*index+1].second};
         }
}
void update(int index,int l,int r,vector<pair<int,int>>&tree,int pos,int val){
             if(pos<l || pos>r)return;
             if(l==r){
                tree[index]={val,1};
                return;
             }
             int mid=(l+r)/2;
             update(index*2,l,mid,tree,pos,val);
             update(index*2+1,mid+1,r,tree,pos,val);
                if(tree[2*index].first==tree[2*index+1].first){
             tree[index]={tree[2*index].first,tree[index*2].second+tree[index*2+1].second};
         }else if(tree[2*index].first<tree[2*index+1].first){
                tree[index]={tree[2*index].first,tree[2*index].second};
            }else{
                tree[index]={tree[2*index+1].first,tree[2*index+1].second};
            }
}
pair<int,int> query(int index,int l,int r,vector<pair<int,int>>&tree,int lq,int rq){
         if(lq>r || rq<l)return {INT_MAX,0};
         if(l>=lq && r<=rq){
            return tree[index];
         }
         int mid=(l+r)/2;
         pair<int,int> leftvalue=query(index*2,l,mid,tree,lq,rq);
         pair<int,int> rightvalue=query(index*2+1,mid+1,r,tree,lq,rq);
          if(leftvalue.first==rightvalue.first){
             return {leftvalue.first,leftvalue.second+rightvalue.second};
         }else if(leftvalue.first<rightvalue.first){
                return {leftvalue.first,leftvalue.second};

         }else{
                return {rightvalue.first,rightvalue.second};
         }
}
int main (){
int n;
cin>>n;
vector<int>arr;
for(int i=0;i<n;i++){
    int r;
    cin>>r;
    arr.push_back(r);
}
vector<pair<int,int>>tree(4*n,{INT_MAX,0});
build(1,0,n-1,tree,arr);
int q;
cin>>q;
for(int i=0;i<q;i++){
    int ch,l,r;
    cin>>ch>>l>>r;
    if(ch==1){
        update(1,0,n-1,tree,l,r);
    }else{
       pair<int,int> ans=query(1,0,n-1,tree,l,r);
       cout<<ans.first<<" "<<ans.second<<'\n';
    }
}

return 0;
}