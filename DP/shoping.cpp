#include<bits/stdc++.h>
using namespace std;
int calculate(int day,int shop,vector<vector<int>>&arr,vector<vector<int>>&dp){
    if(day>=arr.size())return 0;
    if(dp[day][shop]!=-1)return dp[day][shop];
    int ans=0;
    for(int i=0;i<arr[0].size();i++){
        if(i==shop)continue;
        ans=max(ans,arr[day][i]+calculate(day+1,i,arr,dp));
    }
    return dp[day][shop]=ans;
}
int main (){
int n,m;
cin >> n >> m;
vector<vector<int>> arr(n, vector<int>(m));
vector<vector<int>> dp(n, vector<int>(m, -1));  
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin >> arr[i][j];
    }
}
int ans=0;
for(int i=0;i<m;i++){
    ans=max(ans,arr[0][i]+calculate(1,i,arr,dp));
}
cout << ans << '\n';

return 0;
}