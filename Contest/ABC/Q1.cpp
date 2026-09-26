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
string res;
for(int i=0;i<str.size();i++){
    if(str[i]>='0' && str[i]<='9'){
        res+=str[i];
    }
    else{
        continue;
    }
}
cout<<res<<endl;
return 0;
}