#include<bits/stdc++.h>
using namespace std;

int main() {

    string s;
    cin >> s;

    long long index = 0;
    long long ans = 0;
    long long cnt = 0;

    const long long mod = 998244353;

    for (long long i = 1; i < (long long)s.size(); i++) {

        if (s[i] == s[i - 1]) {

            cnt = i - index;

            ans = (ans + ((cnt % mod) * ((cnt + 1) % mod) / 2) % mod) % mod;

            index = i;
        }
    }

    cnt = (long long)s.size() - index;

    ans = (ans + ((cnt % mod) * ((cnt + 1) % mod) / 2) % mod) % mod;

    cout << ans << '\n';

    return 0;
}