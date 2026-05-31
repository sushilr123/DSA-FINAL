/*
you are at the position 1 and you have to reach to position n and you can only move if you are at position i then you can move to i+1 or 2*i or 3*i.find the minimum number of steps required to reach n from 1;
*/

#include<bits/stdc++.h>
using namespace std;
int calculate(int index,int n,vector<int>&dp){
    if(index>n)return INT_MAX;
    if(index==n)return 0;
    if(dp[index]!=-1){
        return dp[index];
    }
    dp[index]=1+min({calculate(index+1,n,dp),calculate(2*index,n,dp),calculate(3*index,n,dp)});
    cout<<dp[index]<<" ";
    return dp[index];
}
int main (){
int n;
cin>>n;
vector<int>dp(n+1,-1);
int x=calculate(1,n,dp);
cout<<'\n';
for(int i=1;i<=n;i++){
    cout<<dp[i]<<" ";
}
cout<<'\n';
cout<<x<<'\n';
return 0;
}