#include<bits/stdc++.h>
using namespace std;
void solution(){
    int n;
    cin>>n;
    vector<int>a(n);
    vector<int> b(101,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[a[i]]++;
    } 
    sort(a.begin(),a.end());
    // cout<<b[0]<<endl;
    vector<int> res;
    for(int j=0;j<=100;j++)
    {
       for(int i=100;i>=0;i--)
       {
          if(b[i]>=1)
          {
            res.push_back(i);
            b[i]--;
          }
       }    
    }
// cout<<res.size()<<endl;
 for(int i=0;i<res.size();i++){
    cout<<res[i]<<" ";
 }
 cout<<endl;
}
int main (){
int t;
cin>>t;
while(t--){
solution();
}
return 0;
}