#include<bits/stdc++.h>
using namespace std;
void solution(){
    int n;
    cin>>n;
    vector<int>a;
    map<int,int>mp;
    for(int i=0;i<n;i++){
        int r;
        cin>>r;
        a.push_back(r);
        mp[r]=i;
    }
    int left=0;
    int right=n-1;
    for(auto it:mp){
        int index=it.second;
        if(index%2==0){
            if(right%2==0){
                right--;
            }else if(left%2==0){
                left++;
            }else{
                cout<<"NO"<<'\n';
                return;
            }
        }else{
            if(right%2==1){
                right--;
            }else if(left%2==1){
                left++;
            }else{
                cout<<"NO"<<'\n';
                return;
            }
        }
    }
 cout<<"YES"<<'\n';
}
int main (){
int t;
cin>>t;
while(t--){
solution();
}
return 0;
}