#include<bits/stdc++.h>
using namespace std;

int main() {

    long long n, k;
    cin >> n >> k;

    vector<vector<long long>> arr(n);
    vector<long long> len(n);

    for(int i = 0; i < n; i++) {

        cin >> len[i];

        for(int j = 0; j < len[i]; j++) {
            long long x;
            cin >> x;
            arr[i].push_back(x);
        }
    }

    vector<long long> c(n);

    for(int i = 0; i < n; i++) {
        cin >> c[i];
    }

    bool found = false;

    for(int i = 0; i < n; i++) {

        long long total = len[i] * c[i];

        if(k > total) {
            k -= total;
        }
        else {

            long long pos = (k - 1) % len[i];

            cout << arr[i][pos] << '\n';

            found = true;
            break;
        }
    }

    return 0;
}