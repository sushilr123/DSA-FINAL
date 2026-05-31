#include<bits/stdc++.h>
using namespace std;
void build(int index,int l,int r,vector<int>&tree,vector<int>&arr){
             if(l==r){
                tree[index]=arr[l];
                return;
             }
             int mid=(l+r)/2;
             build(2*index,l,mid,tree,arr);
             build(2*index+1,mid+1,r,tree,arr);
             tree[index]=tree[2*index]+tree[2*index+1];
}
void update(int index,int l,int r,vector<int>&tree,int pos,int val){
          if(pos<l || pos >r)return;
          if(l==r){
            tree[index]=val;
            return;
          }
          int mid=(l+r)/2;
          update(index*2,l,mid,tree,pos,val);
          update(index*2+1,mid+1,r,tree,pos,val);
          tree[index]=tree[index*2]+tree[index*2+1];
}
int query(int index,int l,int r,vector<int>&tree,int lq,int rq){
         
         if(lq>r || rq<l)return 0;
         if(l>=lq && r<=rq){
            return tree[index];
         }
         int mid=(l+r)/2;
         int leftvalue=query(index*2,l,mid,tree,lq,rq);
         int rightvalue=query(index*2+1,mid+1,r,tree,lq,rq);
         return leftvalue+rightvalue;

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
vector<int>tree(4*n,0);
build(1,0,n-1,tree,arr);
int q;
cin>>q;
for(int i=0;i<q;i++){
    int ch,l,r;
    cin>>ch>>l>>r;
    if(ch==1){
        update(1,0,n-1,tree,l,r);
    }else{
       cout<<query(1,0,n-1,tree,l,r)<<'\n';
    }
}
return 0;
}