#include <bits/stdc++.h>
using namespace std;

/*
    We create a new graph of states.

    State:
        (node, time % W)

    Total states:
        N * W

    From state:
        (u, t)

    we can go to:
        (v, (t+1)%W)

    if:
        - there is an edge u -> v
          OR we stay at same node
        - node u is active at time t
        - node v is active at time t+1

    Then we simply check:
        Does this directed graph contain a cycle?
*/

bool hasCycle(vector<vector<int>>& graph) {

    int n = graph.size();

    // 0 = unvisited
    // 1 = currently in DFS stack
    // 2 = completely processed
    vector<int> state(n, 0);

    function<bool(int)> dfs = [&](int node) {

        state[node] = 1;

        for (int next : graph[node]) {

            // back edge -> cycle found
            if (state[next] == 1)
                return true;

            // visit unvisited node
            if (state[next] == 0) {
                if (dfs(next))
                    return true;
            }
        }

        state[node] = 2;

        return false;
    };

    for (int i = 0; i < n; i++) {

        if (state[i] == 0) {

            if (dfs(i))
                return true;
        }
    }

    return false;
}

void solve() {

    int N, M;
    cin >> N >> M;

    vector<pair<int,int>> edges;

    // original graph edges
    for (int i = 0; i < M; i++) {

        int u, v;
        cin >> u >> v;

        u--;
        v--;

        edges.push_back({u, v});
        edges.push_back({v, u});
    }

    int W;
    cin >> W;

    vector<string> S(N);

    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }

    // add self loops (stay at same node)
    for (int i = 0; i < N; i++) {
        edges.push_back({i, i});
    }

    /*
        Build state graph

        state id:
            time * N + node
    */

    vector<vector<int>> graph(N * W);

    for (auto [u, v] : edges) {

        for (int t = 0; t < W; t++) {

            int nextTime = (t + 1) % W;

            // both states must be active
            if (S[u][t] == 'o' && S[v][nextTime] == 'o') {

                int from = t * N + u;
                int to   = nextTime * N + v;

                graph[from].push_back(to);
            }
        }
    }

    bool ans = hasCycle(graph);

    cout << (ans ? "Yes" : "No") << '\n';
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}