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

void update(int index,int l,int r,vector<int>&tree,int pos,int val,bool flag){
              
             if(pos<l || pos>r)return;
             if(l==r){
                if(flag){
                tree[index]+=val;
                return;
                }else{
                    tree[index]-=(-val);
                    return;
                }
             }
             int mid=(l+r)/2;
             update(index*2,l,mid,tree,pos,val,flag);
             update(index*2+1,mid+1,r,tree,pos,val,flag);
             tree[index]=tree[index*2]+tree[index*2+1];
}
int query(int index,int l,int r,vector<int>&tree,int lq,int rq){
             
          if(lq>r || rq<l)return 0;
          if(l>=lq && r<=rq){
    return tree[index];
}
          int mid=(l+r)/2;
          int x=query(index*2,l,mid,tree,lq,rq);
          int y=query(index*2+1,mid+1,r,tree,lq,rq);
        return x+y;
}
int main (){
   int n;
   cin>>n;
   vector<int>tree(4*n,0);
   int q;
   cin>>q;
   for(int i=0;i<q;i++){
      int ch,l,r,v;
      cin>>ch;
      if(ch==1){
         cin>>l>>r>>v;
        update(1,0,n-1,tree,l,v,true);
        update(1,0,n-1,tree,r+1,v,false);
      }else{
        cin>>v;
        cout<<query(1,0,n-1,tree,0,v)<<'\n';
      }
   }
return 0;
}