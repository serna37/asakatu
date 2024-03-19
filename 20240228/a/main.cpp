#include <bits/stdc++.h>
using namespace std;
int main() {
    int N = 4, M = 3;
    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        A--, B--;
        G[A].push_back(B);
        G[B].push_back(A);
    }
    queue<int> q;
    q.push(0);
    vector<int> dis(N, -1);
    dis[0] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int nv : G[v]) {
            if (dis[nv] == -1) {
                dis[nv] = dis[v] + 1;
                q.push(nv);
            }
        }
    }
    if (dis[3] == 3) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
