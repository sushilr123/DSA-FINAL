#include<bits/stdc++.h>
using namespace std;
void build(int index,int l,int r,vector<int>&tree,vector<int>&arr){
        if(l==r){
            tree[index]=arr[l];
            return;
        }
        int mid=(l+r)/2;
        build(index*2,l,mid,tree,arr);
        build(index*2+1,mid+1,r,tree,arr);
        tree[index]=tree[index*2]+tree[index*2+1];
}
void update(int index,int l,int r,vector<int>&tree,int pos,int val){
                 if(l>pos || r<pos)return;
                 if(l==r){
                    tree[index]=val;
                 }
                 int mid=(l+r)/2;
                 update(index*2,l,mid,tree,pos,val);
                 update(index*2+1,mid+1,r,tree,pos,val);
                 tree[index]=tree[index*2]+tree[index*2+1];
}

int query(int index,int l,int r,vector<int>&tree,int lq,int rq){
       if(l)
}
int main (){

return 0;
}