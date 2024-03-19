#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, Q;
    cin >> N >> Q;
    vector<vector<int>> G(N);
    for (int i = 0; i < N - 1; i++) {
        int A, B;
        cin >> A >> B;
        A--, B--;
        G[A].push_back(B);
        G[B].push_back(A);
    }
    // 単一始点BFS
    queue<int> q;
    vector<int> dis(N, -1);
    q.push(0);
    dis[0] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto &&nv : G[v]) {
            if (dis[nv] == -1) {
                dis[nv] = dis[v] + 1;
                q.push(nv);
            }
        }
    }
    while (Q--) {
        int c, d;
        cin >> c >> d;
        --c, --d;
        int D = dis[d] - dis[c];
        cout << (D & 1 ? "Road" : "Town") << endl;
    }
}
