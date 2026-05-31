#include<bits/stdc++.h>
using namespace std;
int solve(int last,int index,int count,int k,int n,vector<vector<vector<int>>>&dp){
      if(index==n)return 1;
      if(dp[last][index][count]!=-1)return dp[last][index][count];
      int ans=0;
      if(last==0){
         ans+=solve(1,index+1,1,k,n,dp);
         if(count<k-1){
           ans+=solve(0,index+1,count+1,k,n,dp); 
         }
      }else{
        ans+=solve(0,index+1,1,k,n,dp);
         if(count<k-1){
           ans+=solve(1,index+1,count+1,k,n,dp); 
         }
      }
      return dp[last][index][count]= ans;
}
int main (){
//int t;
int n,k;
cin>>n>>k;
vector<vector<vector<int>>> dp(
    2,
    vector<vector<int>>(n + 1, vector<int>(k + 1, -1))
);
int ans=solve(0,1,1,k,n,dp)+solve(1,1,1,k,n,dp);
cout<<ans<<'\n';
return 0;
}