#include<bits/stdc++.h>
using namespace std;
void kmp(string str,vector<int>&lps){
     int i=0,j=-1,n=str.size();
     lps[0]=-1;
     while(i<=n){
        while(j!=-1 && str[i]!=str[j]){
            j=lps[j];
        }
        i++;
        j++;
        lps[i]=j;
     }
}
int main (){

string s,t;
cin>>s>>t;
string res="";
res+=(s+"#"+t);
int n=res.size();
vector<int>lps(n+1);
// cout<<res<<'\n';?
kmp(res,lps);
int x=s.size();
bool flag=false;
for(int i=1;i<=n;i++){
    if(lps[i]==x){
        flag=true;
    }
}
if(flag)cout<<"true"<<'\n';
else cout<<"false"<<'\n';
return 0;
}