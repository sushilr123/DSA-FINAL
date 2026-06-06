#include<bits/stdc++.h>
using namespace std;
void kmp(string str,vector<int>&lps){
    int i=0,j=-1;lps[0]=-1;
    int n=str.size();
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
string str;
cin>>str;
int n=str.size();
vector<int>lps(n+1);
kmp(str,lps);
for(int i=0;i<=n;i++){
    cout<<lps[i]<<" ";
}cout<<'\n';
int x=n-lps[n];
if(lps[n] && lps[n]%x==0){
    cout<<"Yes"<<'\n';
}else{
    cout<<"No"<<'\n';
}
cout<<'\n';
return 0;
}