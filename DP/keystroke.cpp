#include<bits/stdc++.h>
using namespace std;

map<tuple<int,int,int,int>, int> dp;

int solve(int count,int stroke,int lastcopy,int selected,int n){

    if(stroke > n)
        return 0;

    auto state = make_tuple(count, stroke, lastcopy, selected);

    if(dp.count(state))
        return dp[state];

    int ans = count;

    // Press A
    ans = max(ans,
        solve(count + 1, stroke + 1, lastcopy, 0, n)
    );

    // Copy All
    ans = max(ans,
        solve(count, stroke + 1, count, count, n)
    );

    // Select All
    ans = max(ans,
        solve(count, stroke + 1, selected, 0, n)
    );

    // Paste
    if(lastcopy > 0){
        ans = max(ans,
            solve(count + lastcopy, stroke + 1, lastcopy, 0, n)
        );
    }

    return dp[state] = ans;
}

int main (){

    int n;
    cin >> n;

    int ans = solve(1,1,0,0,n);

    cout << ans << '\n';

    return 0;
}