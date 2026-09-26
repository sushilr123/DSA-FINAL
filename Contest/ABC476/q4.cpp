#include<bits/stdc++.h>
using namespace std;
int main (){
long long int n,m,k;
cin>>n>>m>>k;
long long int x,y;
cin>>x>>y;
priority_queue<pair<long long int,long long int>> pq;
for(int i=0;i<n;i++){
    long long int r;
    cin>>r;
    pq.push({r,0});
}
for(int i=0;i<m;i++){
    long long int r;
    cin>>r;
    pq.push({r,1});
}
long long int count=0;
while(!pq.empty()){
    pair<long long int,long long int> p=pq.top();
    pq.pop();
    if(p.second==1){
         long long int val=p.first;
         long long int rem=(val%k==0)?(val/k):(val/k+1);
         if(y>=rem){
            count++;
            y-=rem;
            x+=(rem*k-val);
         }
    }else{
        int val=p.first;
        if(x>=val){
            count++;
            x-=val;
        }else if(y*k>=val ){
            count++;
            int rem=(val%k==0)?(val/k):(val/k+1);
            y-=rem;
            x+=(rem*k-val);
        }else{
            break;
        }
        
    }
}
cout<<count<<endl;
return 0;
}