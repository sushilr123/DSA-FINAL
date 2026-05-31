#include<bits/stdc++.h>
using namespace std;
//void solution(){
//}
int main (){
int n;
cin >> n;
std::map<std::pair<int, int>, std::vector<int>, std::greater<std::pair<int, int>>> mp;
for(int i=0;i<n;i++){
    int a,b;
    cin >> a >> b;
    mp[{b,a}].push_back(i+1);
}
for(auto it:mp){
    for(auto it2:it.second){
        cout << it2 << '\n';
    }
}
return 0;
}