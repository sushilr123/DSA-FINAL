#include<bits/stdc++.h>
using namespace std;
//void solution(){
//}
int main (){
long long int s,p,r;
cin >> s >> p >> r;
long long int m;
cin >> m;
for(long long int i=0;i<m;i++){
    long long int a,b;
    cin >> a >> b;
    if(a==1){
        s+=b;
    }
    else if(a==2){
        s-=p*b;
    }
}
cout << s-r << '\n';
return 0;
}