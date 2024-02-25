#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        A--;
        B--;
        G[A].push_back(B);
    }
    set<int> winner;
    for (int i = 0; i < N; i++) {
        winner.insert(i);
    }
    queue<int> q;
    for (int i = 0; i < N; i++) {
        q.push(i);
        while (!q.empty()) {
            auto v = q.front();
            q.pop();
            for (int n : G[v]) {
                q.push(n);
                winner.erase(n);
            }
        }
    }
    if (winner.size() != 1) {
        cout << -1 << endl;
    } else {
        cout << (*winner.begin()) + 1 << endl;
    }
}
