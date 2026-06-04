#include <bits/stdc++.h>
using namespace std;
 int pow(int a,int b){
     int res=1;
     for(int i=1;i<=b;i++){
         res=(res*a)%998244353;
     }
     return res;
 }
 int ncr(int n, int r) {
    if (r > n) return 0;
    if (r == 0 || r == n) return 1;
    long long res = 1;
    for (int i = 1; i <= r; i++) {
        res = res * (n - i + 1) / i;
    }
    return res % 998244353;
}
void solve(){
    int n,k;
    cin>>n>>k;
    long long int sum=0;
    int mod=998244353;
    for(int i=1;i<=k;i++){
        long long int p=pow(i,k)-(i-1);
        int x=n-i;
        int r=n-k;
        long long int q=ncr(x,r);
        sum=(sum+p*q)%mod;  
    }
    cout<<sum%mod<<'\n'; 
}
int main() {
	// your code goes here
 int n;
 cin>>n;
 while(n--){
     solve();
 }
}