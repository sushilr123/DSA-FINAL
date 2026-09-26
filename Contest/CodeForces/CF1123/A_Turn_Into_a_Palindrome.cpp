#include<bits/stdc++.h>
using namespace std;
void solution(){
    int n;
    char c;
    cin>>n>>c;
    string s;
    cin>>s;
    int count=0;
    for(int i=0;i<n/2;i++){
        if(s[i]!=s[n-i-1]){
            if(s[i]==c || s[n-i-1]==c){
                count++;
            }
            else{
                count+=2;
            }
        }
    }
    cout<<count<<endl;
}
int main (){
int t;
cin>>t;
while(t--){
solution();
}
return 0;
}