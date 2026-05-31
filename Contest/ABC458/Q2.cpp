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
int h,w;
cin>>h>>w;
for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
        int count=0;
        if(i>0)count++;
        if(i<h-1)count++;
        if(j>0)count++;
        if(j<w-1)count++;
        cout<<count<<" ";
    }
    cout<<'\n';
}
return 0;
}