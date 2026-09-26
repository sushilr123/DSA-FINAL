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
vector<int> a(n);
for(int i=0;i<n;i++){
    cin>>a[i];
}
std::priority_queue<int, std::vector<int>, std::greater<int>> pq;;
for(int i=0;i<3;i++){
    pq.push(a[i]);
}
cout<<pq.top()<<endl;
for(int i=3;i<n;i++){
    if(a[i]>pq.top()){
        pq.pop();
        pq.push(a[i]);
        cout<<pq.top()<<endl;
    }else{
        cout<<pq.top()<<endl;
    }
}
return 0;
}