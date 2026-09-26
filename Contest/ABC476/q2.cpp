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
int n;
cin>>n;
string s;
string t;
cin>>s;
cin>>t;
bool flag=true;
for(int i=0;i<n;i++){
    if(s[i]!=t[i] && t[i]!='*'){
        flag=false;
        break;
    }
}
if(flag){
    cout<<"Yes"<<endl;
}
else{
    cout<<"No"<<endl;
}
return 0;
}