#include<bits/stdc++.h>
using namespace std;

int maxSum(int i,vector<int>&arr,vector<int>&dp){
    if(i<0)return 0;
    if(dp[i]!=-1)return dp[i];
    return dp[i]=arr[i]+max(0,maxSum(i-1,arr,dp));
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
vector<int>dp(n,-1);
int maxi=INT_MIN;
maxSum(n-1,arr,dp);
for(int i=0;i<n;i++){
    maxi=max(maxi,dp[i]);
}
 cout<<maxi<<'\n';
return 0;
}