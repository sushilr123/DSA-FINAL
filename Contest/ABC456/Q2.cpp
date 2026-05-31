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
int a1=0,b1=0,c1=0,a2=0,b2=0,c2=0,a3=0,b3=0,c3=0;
for(int i=0;i<6;i++){
    int r;
    cin>>r;
    if(r==4){
        a1++;
    }
    if(r==6){
        b1++;
    }
    if(r==5){
        c1++;
    }
}
for(int i=0;i<6;i++){
    int r;
    cin>>r;
    if(r==4){
        a2++;
    }
    if(r==6){
        b2++;
    }
    if(r==5){
        c2++;
    }
}
for(int i=0;i<6;i++){
    int r;
    cin>>r;
    if(r==4){
        a3++;
    }
    if(r==6){
        b3++;
    }
    if(r==5){
        c3++;
    }
}
    int sum=a1*b2*c3+a1*c2*b3+b1*a2*c3+b1*c2*a3+c1*a2*b3+c1*b2*a3;
    int total=6*6*6;
    double ans=(double)sum/total;
    cout<<fixed<<setprecision(10)<<ans<<'\n';

return 0;
}

