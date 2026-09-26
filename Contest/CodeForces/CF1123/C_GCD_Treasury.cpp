#include<bits/stdc++.h>
using namespace std;
void solution(){
    long long int n,x;
    cin>>n>>x;
    vector<long long int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<long long int>prime_factors;
    for(int i=2;i*i<=x;i++){
        if(x%i==0){
            prime_factors.push_back(i);
            while(x%i==0){
                x/=i;
            }
        }
    }
    if(x>1){
        prime_factors.push_back(x);
    }
    long long int maxi=0;
    for(int i=0;i<prime_factors.size();i++){
        long long int count=0;
         for(int j=0;j<n;j++){
            if(a[j]%prime_factors[i]==0){
               count+=a[j];
            }
         }
         maxi=max(maxi,count);
    }
    cout<<maxi<<endl;
}
int main (){
int t;
cin>>t;
while(t--){
solution();
}
return 0;
}