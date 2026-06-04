#include<bits/stdc++.h>
using namespace std;

int main (){
int n,m;
cin>>n>>m;
int count=0;
while(m!=0){
   count++;
   m=n%m;
}
cout<<count<<'\n';
return 0;
}