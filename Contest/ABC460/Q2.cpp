#include<bits/stdc++.h>
using namespace std;

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    long long x1, y1, r1, x2, y2, r2;
    while(n--){
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        
        long long dx = x1 - x2;
        long long dy = y1 - y2;
        long long d_sq = dx * dx + dy * dy; 
        long long r_sum_sq = (r1 + r2) * (r1 + r2);
        long long r_diff_sq = (r1 - r2) * (r1 - r2); 
        

        if(d_sq > r_sum_sq || d_sq < r_diff_sq){
            cout << "No" << '\n';
        } else {
            cout << "Yes" << '\n';
        }
    }
    return 0;
}
