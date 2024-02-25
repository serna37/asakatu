#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, Q;
    cin >> N >> Q;
    vector<vector<int>> G(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<int> d(N, 0);
    while (Q--) {
        int p, x;
        cin >> p >> x;
        p--;
        d[p] += x;
    }
    queue<int> q;
    vector<bool> vis(N, false);
    q.push(0);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        vis[v] = true;
        for (int nv : G[v]) {
            if (!vis[nv]) {
                d[nv] += d[v];
                q.push(nv);
            }
        }
    }
    for (int i = 0; i < N; i++) {
        if (i) cout << " ";
        cout << d[i];
    }
    cout << endl;
}
