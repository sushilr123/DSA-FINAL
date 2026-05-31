/*Description

You are given N strings. You are allowed to reverse the i-th string with a cost c[i]. You have to find the minimum cost needed to sort the strings in lexicographical order.

String A is lexicographically smaller than string B if it is shorter than B (|A| < |B|) and is its prefix, or if none of them is a prefix of the other and at the first position where they differ character in A is smaller than the character in B.

Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains one integer N.

The second line of each test case contains N space-separated integers - the cost.

Each of the next N lines contains a string.

Output Format

For each test case, print the minimum cost needed to sort the strings in lexicographical order. If it is impossible to sort the strings print -1.

Constraints

1≤ T ≤ 100

1≤ N ≤ 105

0≤ Ci ≤ 109

1≤ |S| ≤ 105

It is guaranteed that the total length of these strings doesn't exceed 106.

Sample Input
3
3
2 6 7
aca
aad
fba

3
5 1 1
pbc
cbe
qbf

2
4 5
baa
aaa

Sample Output 
6
6
-1
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll INF = 1e18;

void solve() {

    int n;
    cin >> n;

    vector<ll> cost(n);

    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }

    vector<string> s(n), rev(n);

    for (int i = 0; i < n; i++) {

        cin >> s[i];

        rev[i] = s[i];

        reverse(rev[i].begin(),
                rev[i].end());
    }

    /*
        dp[i][0]
        minimum cost till index i
        when current string is NOT reversed

        dp[i][1]
        minimum cost till index i
        when current string IS reversed
    */

    vector<vector<ll>> dp(
        n,
        vector<ll>(2, INF)
    );

    // Base case

    dp[0][0] = 0;
    dp[0][1] = cost[0];

    for (int i = 1; i < n; i++) {

        // Current NOT reversed

        if (s[i - 1] <= s[i] &&
            dp[i - 1][0] != INF) {

            dp[i][0] =
            min(dp[i][0],
                dp[i - 1][0]);
        }

        if (rev[i - 1] <= s[i] &&
            dp[i - 1][1] != INF) {

            dp[i][0] =
            min(dp[i][0],
                dp[i - 1][1]);
        }

        // Current reversed

        if (s[i - 1] <= rev[i] &&
            dp[i - 1][0] != INF) {

            dp[i][1] =
            min(dp[i][1],
                dp[i - 1][0] + cost[i]);
        }

        if (rev[i - 1] <= rev[i] &&
            dp[i - 1][1] != INF) {

            dp[i][1] =
            min(dp[i][1],
                dp[i - 1][1] + cost[i]);
        }
    }

    ll answer =
        min(dp[n - 1][0],
            dp[n - 1][1]);

    if (answer == INF) {
        cout << -1 << '\n';
    }
    else {
        cout << answer << '\n';
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}