#include<bits/stdc++.h>
using namespace std;
//void solution(){
//}
int main (){
//int t;
//cin>>t;
//while(t--){
//solution();
//}
string str;
cin>>str;
int n;
cin>>n;
string ans="";
for(int i=n;i<str.size()-n;i++)
{
     ans+=str[i];
}
cout<<ans<<'\n';
return 0;
}