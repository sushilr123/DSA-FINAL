/*
https://codeforces.com/contest/1620/problem/A
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        int n = str.size();
        bool equal = true;
        for (int i = 0; i < n / 2; i++) {
            if (str[i] != str[n - 1 - i]) {
                equal = false;
                break;
            }
        }
    }
    return 0;
}