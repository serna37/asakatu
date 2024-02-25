#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M, E;
    cin >> N >> M >> E;
    vector<vector<int>> G(N + M + 1);
    for (int i = 0; i < E; i++) {
        int U, V;
        cin >> U >> V;
        G[U].push_back(V);
        G[V].push_back(U);
    }
    int Q;
    cin >> Q;
}
