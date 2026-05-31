#include<bits/stdc++.h>
using namespace std;

int main (){
string s;
cin>>s;
long long int ans=0;
int n=s.size();

for(int i=0;i<n;i++){
    if(s[i]=='C'){
        int x=min(i,n-i-1);
        ans+=(x+1);
    }
}
cout<<ans<<'\n';
return 0;
}