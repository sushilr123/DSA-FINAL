#include<bits/stdc++.h>
using namespace std;
//void solution(){
//}
int main (){
string str="HelloWorld";
int x;
cin>>x;
for(int i=0;i<str.size();i++){
    if(i!=x-1){
        cout<<str[i];
    }
}
cout<<'\n';
return 0;
}