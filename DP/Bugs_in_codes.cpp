/*Description

There are N people working on a project, where they have to write exactly M lines of code. The i-th person makes Ai bugs in every line of code that he writes. The first person writes X1 lines of code, the second person writes X2 lines of code, and so on, such that X1 + X2 + ….+ Xn = M. You have to find the number of distinct plans (X1, X2,….Xn, where Xi≥0 and sum of Xi = M) which have at most B bugs. Since the answer might be large, print it modulo 109+7.

Input Format

The first line contains four space-separated integers N, M, B.

The second line contains N space-separated integers.

Output Format

Print the number of distinct plans which have exactly B bugs. Since the answer might be large, print it modulo 109+7.

Constraints

1≤ N, M ≤ 500

0≤ B ≤ 500

0≤ Ai ≤ 500

Sample Input 1
2 3 3
1 2
Sample Output 1
1

*/

#include<bits/stdc++.h>
using namespace std;
// int calculate(int i,vector<int>&arr,int m,int b,int currm,int currb){
//             if(currm>m || currb>b)return 0;
//             if(i>=arr.size())return 0;
//             if(currm==m)return 1;
//             return calculate(i,arr,m,b,currm+1,currb+arr[i])+calculate(i+1,arr,m,b,currm,currb);
// }
int main (){
int mod=1e9+7;
int n,m,b;
cin>>n>>m>>b;
vector<int>arr;
for(int i=0;i<n;i++){
    int r;
    cin>>r;
    arr.push_back(r);
}
// cout<<calculate(0,arr,m,b,0,0)<<'\n';
vector<vector<int>>dp(m+1,vector<int>(b+1,0));
dp[0][0]=1;
for(int i=0;i<n;i++){
    for(int j=1;j<=m;j++){
        for(int ba=arr[i];ba<=b;ba++){
            dp[j][ba]=(dp[j][ba]+dp[j-1][ba-arr[i]])%mod;
        }
    }
}
int ans=0;
for(int i=0;i<=b;i++){
    ans=(ans+dp[m][i])%mod;
}
cout<<ans<<'\n';
return 0;
}