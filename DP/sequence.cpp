#include<bits/stdc++.h>
using namespace std;
int solve(int last,int index,int n,vector<vector<int>>&dp){
      if(index==n){
         return 1;
      }
      if(dp[last][index]!=-1)return dp[last][index];
      int ans=0;
      if(last==0){
         ans+=solve(0,index+1,n,dp)+solve(1,index+1,n,dp)+solve(2,index+1,n,dp);
      }else if(last==1){
        ans+=solve(0,index+1,n,dp)+solve(2,index+1,n,dp);
      }else{
        ans+=solve(0,index+1,n,dp)+solve(1,index+1,n,dp)+solve(2,index+1,n,dp);
      }
      return dp[last][index]=ans;
}
int main (){
int n;
cin>>n;
vector<vector<int>>dp(3,vector<int>(n+1,-1));
int ans=solve(0,1,n,dp)+solve(1,1,n,dp)+solve(2,1,n,dp);
cout<<ans<<'\n';
return 0;
}